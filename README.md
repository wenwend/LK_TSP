# LK_TSP

## Input files
Each line defines a city and each line has three numbers separated by white space.
1. The first number is the city identifier
2. The second number is the city’s x-coordinate
3. The third number is the city’s y-coordinate.

## Compiling and running
1. Run `make` to compile. g++ is required.
2. To run, type in `./TwoOptMain <input>`, where `<input>` is the input file with the format specified above.
3. The results will be saved in a file with filename `<input>.tour`

## Output files
The first line of the output file has the tour length. After the first line, each subsequent line denotes the city identifier of the next city to visit on the tour.
