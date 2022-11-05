CC = gcc

game: Game.c TTTengine.c Bot.c Board.c 
	$(CC) -o TicTacToe Game.c

clean:
	rm -f TicTacToe *.o