

import pathlib
import subprocess
import sys
import tempfile

BASE = pathlib.Path(__file__).resolve().parents[1]
COMPILADOR = "g++"


def executar():
    falhas = 0
    total = 0

    with tempfile.TemporaryDirectory() as temporario:
        pasta_temp = pathlib.Path(temporario)

        for numero in range(1, 16):
            codigo = BASE / "desafios" / f"{numero:02d}" / "main.cpp"
            pasta_testes = BASE / "testes" / f"{numero:02d}"
            executavel = pasta_temp / f"desafio{numero:02d}"

            compilacao = subprocess.run(
                [
                    COMPILADOR,
                    "-std=c++17",
                    "-O2",
                    "-Wall",
                    "-Wextra",
                    str(codigo),
                    "-o",
                    str(executavel)
                ],
                capture_output=True,
                text=True
            )

            if compilacao.returncode != 0:
                print(f"[ERRO] Desafio {numero:02d}: falha na compilacao")
                print(compilacao.stderr)
                falhas += 1
                continue

            entradas = sorted(pasta_testes.glob("*.in"))

            if not entradas:
                print(f"[AVISO] Desafio {numero:02d}: nenhum teste encontrado")
                continue

            for entrada in entradas:
                esperado = entrada.with_suffix(".out")

                if not esperado.exists():
                    print(f"[AVISO] Sem arquivo esperado para {entrada.name}")
                    continue

                total += 1

                with entrada.open("rb") as arquivo:
                    resultado = subprocess.run(
                        [str(executavel)],
                        stdin=arquivo,
                        capture_output=True
                    )

                saida_obtida = resultado.stdout.replace(b"\r\n", b"\n")
                saida_esperada = esperado.read_bytes().replace(b"\r\n", b"\n")

                if (
                    resultado.returncode != 0
                    or saida_obtida != saida_esperada
                ):
                    falhas += 1
                    print(f"[FALHA] Desafio {numero:02d} - {entrada.name}")

                    if resultado.returncode != 0:
                        print(resultado.stderr.decode(errors="replace"))

                    if saida_obtida != saida_esperada:
                        print("Esperado:", repr(saida_esperada))
                        print("Obtido:", repr(saida_obtida))

                else:
                    print(f"[OK] Desafio {numero:02d} - {entrada.name}")

    print(f"\nTestes executados: {total}")
    print(f"Falhas: {falhas}")

    return 1 if falhas else 0


if __name__ == "__main__":
    sys.exit(executar())
