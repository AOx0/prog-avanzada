set dotenv-load := false

@run file:
    g++ {{file}} -o /tmp/out && /tmp/out
