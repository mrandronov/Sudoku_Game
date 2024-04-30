
import sys
from wonderwords import RandomWord

r = RandomWord()
f = open( "sudoku.csv", "r" )

f.readline()

count = 1
for line in f:
        puzzle = line.split( ',' )

        name1 = r.word( include_parts_of_speech=[ "adjective" ] )
        name2 = r.word( include_parts_of_speech=[ "noun" ] )
        name = name1 + " " + name2
        fileName = "SudokuPuzzles/puzzle" + str( count ) + ".sp"

        sp = open( fileName, "w" )
        sp.write( name )
        sp.write( '\n' )
        sp.write( puzzle[ 0 ] )
        sp.write( '\n' )
        sp.write( puzzle[ 1 ] )

        print( f"puzzle #{ count } : done {name}" )
        count += 1

        if ( count >= 100 ):
                break;
        

