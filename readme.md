# CSV-Preprocessor

- Takes a file (.csvp) as input, and converts it to a comma seperated value file (.csv)
  - The following steps are taken on the input file
    - Step 1
      - Read all values from the cells
        - Calculate results for cells with no dependencies.
        - Keep information concerning dependencies on any other cells.
    - Step 2
      - Attempt to resolve any dependencies to place the value in the cells.
      - Do any calculations on the resolved values.
    - Step 3
      - Write resulting csv data to a new file.
