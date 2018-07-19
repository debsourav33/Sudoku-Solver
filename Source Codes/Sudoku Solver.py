sudoku=[]
solved= False

def blocked(val,i,j):
    i-=i%3
    j-=j%3

    for x in range(i,i+3):
        for y in range(j,j+3):
            if(sudoku[x][y]==val):
                return True
    return False

def notIllegal(val,i,j):
    for x in range(9):
        if(sudoku[i][x]==val):
            return False

    for x in range(9):
        if(sudoku[x][j]==val):
            return False

    if(blocked(val,i,j)):
        return False

    return True


def solve(cell):

    i= int (cell/9)
    j= int (cell%9)

    if(i==9):
        global solved
        solved= True
        print()
        for x in range(9):
            for y in range(9):
                print(sudoku[x][y], end=" ")
            print()
        return

    if(sudoku[i][j]!=0):
        solve(cell+1)
        return

    for x in range(1,10):
        if(notIllegal(x,i,j)):
            sudoku[i][j]=x
            solve(cell+1)
            if(solved):
                return
            sudoku[i][j]=0 #Back Tacking



if __name__ == '__main__':
    print("/*Place 0 for cells that don't have an entry\nSeperate columns with space and rows with new line*/\n")

    for i in range(0,9):
        row=[]
        inp = list(map(int,input().split()))

        sudoku.append(inp)

    solve(0)


