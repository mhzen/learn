# FORCE just to run every command from where your terminal is, not where the justfile is
set working-directory := invocation_directory()

# Compile C or C++
build path:
    #!/usr/bin/env bash
    # Now that working-directory is set, 'path' is exactly what you typed
    FILE="{{ path }}"

    if [ ! -f "$FILE" ]; then
        echo "Error: Cannot find '$FILE' in $(pwd)"
        exit 1
    fi

    # Extract extension and base name
    EXT="${FILE##*.}"
    BASE="${FILE%.*}"
    OUT="$BASE.out"

    if [ "$EXT" == "c" ]; then
        echo "Compiling C: $FILE -> $OUT"
        gcc "$FILE" -o "$OUT" -pthread -O3
    elif [ "$EXT" == "cpp" ] || [ "$EXT" == "cc" ]; then
        echo "Compiling C++: $FILE -> $OUT"
        g++ "$FILE" -o "$OUT" -pthread -O3
    else
        echo "Error: Unsupported extension .$EXT"
        exit 1
    fi

# Build and Run
run path:
    just build {{ path }}
    @echo "--- Output of {{ path }} ---"
    ./{{ file_stem(path) }}.out
