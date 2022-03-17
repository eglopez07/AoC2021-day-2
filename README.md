# AoC2021-day-2
My solution to the Advent of Code 2021 day 2 puzzles. You can find a link to those puzzles [here](https://adventofcode.com/2021/day/2).

For this, I wanted to really take advantage of what C++ has to offer to write a solution that should be fast and efficient in terms of time.
Hash maps are incredibly powerful, and smart pointers are a handy way to clean up simple objects.

When I worked on this, I actually started out by whiteboarding my logic and how I would organize my class to implement what I needed. I ended up adding a fair bit over time anyway to account for exception handling, but the final design is remarkably close to what I originally planned. It looks like my logic held up!

## Part 1
First we go through a file line-by-line for input and, after checking that it is in the correct format, we add it to the hash map and then update the specific values we want. The hash map is useful for keeping track of what lines we have already seen before, so we don't have to worry about using stoi() over and over on the same strings; we can just get the number we already found from that line before and perform the same calculation. It is a minor optimization but can be handy when you're working with thousands or even millions of lines (our input only made us work with 1000 lines.) Can't beat instant access speed.

I added some catches to help with debugging my logic, and even wrote a unique exception for the string validation. Once again we are using command line arguments because I think they are simple to work with. In the future, I would like to implement a way for the user to specify the file path for input within the program if no command line arguments are available or they are otherwise invalid.

## Part 2
This could not have been simpler to implement. Just some minor additions to account for the new variable and an updated function for performing actions based on inputs received. It went well and passed with flying colors!

On to day 3!
