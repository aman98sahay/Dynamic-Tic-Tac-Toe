# Dynamic Tic Tac Toe

Is a new take on the normal Tic Tac Toe, with a way to expand this game that we all have been playing for a long time.

Rules of the game.

1. Before start the number of rows and columns have to be selected. (suppose the player have selected r rows and c columns (r and c can be different)
2. The Game is played between 2 player, one will select 'O' and the other will select 'X', and will take turns to select 
	a block in the mesh( the rows and columns we have decided).
3. This will go on till either all the boxes are filled, or one of the players completes the winning condition. 

 ## Requirements
cmake version > 3.20

g++ (for mac and linux) and Visual Studio 2022 for windows (for windows will also work with mingw)

## What is the winning condition

```
c = number of columns
r = number of rows
That a player is able to mark at-least min(c,r) block in a straight line (could be horizontal/vertical/diagonal)


```



## How to build 

(Note you have to install cmake on your system for this to work)

```
# goto any folder where u wish to clone & build
cd C:\DesiredFolder\
git clone https://github.com/aman98sahay/Dynamic-Tic-Tac-Toe.git 

mkdir build 
cd build 
cmake ..
cmake --build .

```

## Works on Linux/Mac/Windows

## What to expect 
### running on MacOS 
<img width="589" alt="Screenshot 2024-02-14 at 8 31 22 AM" src="https://github.com/aman98sahay/Dynamic-Tic-Tac-Toe/assets/51999416/747418dc-6cb6-4998-a582-565bbde89954">

<img width="351" alt="Screenshot 2024-02-14 at 8 31 46 AM" src="https://github.com/aman98sahay/Dynamic-Tic-Tac-Toe/assets/51999416/db3db314-6b19-4608-8d78-1ef1bbc3320c">

### running on Windows 
![Screenshot 2024-04-08 185658](https://github.com/aman98sahay/Dynamic-Tic-Tac-Toe/assets/51999416/6c7af241-6c2b-4f94-a0e0-0badbd43880c)

### running on iSH app in iOS 
![WhatsApp Image 2024-04-08 at 18 57 30_463ae127](https://github.com/aman98sahay/Dynamic-Tic-Tac-Toe/assets/51999416/1198717f-77d2-4265-b81f-da3ba4a8c835)


