set dotenv-load := false

@run num num_as:
    cd tarea{{num}}_prog && g++ ejercicio{{num_as}}.cpp -o /tmp/out && /tmp/out

@runl num num_as:
    cd tarea{{num}}_prog && g++ ejercicio{{num_as}}.cpp -o /tmp/out && leaks --atExit -- /tmp/out

@r num:
    cd tarea100_prog && g++ ejercicio{{num}}.cpp -o /tmp/out && /tmp/out
