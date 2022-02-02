set dotenv-load := false

@run num num_as:
    cd tarea{{num}}_prog && g++ ejercicio{{num_as}}.cpp -o /tmp/out && /tmp/out
