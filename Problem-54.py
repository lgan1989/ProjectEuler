import sys

f = open("poker.txt" , "r")

sys.stdout = open("poker_output.txt" , "w") 
ans = 0
dic = {'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'T':10,'J':11,'Q':12,'K':13,'A':14}
def straight(lst):
    for i in range(1,len(lst)):
        if lst[i][0]  - lst[i - 1][0]  != 1:
            return (False , 0)
    return (True , lst[0][0])

def flush(lst):
    for i in range(1,len(lst)):
        if (lst[i][1] != lst[i - 1][1]):
            return (False , 0)   
    return (True , lst[0][0])
def royal(lst):
    return lst[0][0] == 10

def fok(lst):
    if (lst[1][0] == lst[4][0]):
        return (True , lst[1][0])
    if (lst[0][0] == lst[3][0]):
        return (True , lst[0][0])
    return (False , 0)
def tok(lst):
    for i in range(2 , -1 , -1):
        if (lst[i][0] == lst[i + 2][0]):
            return (True , lst[i][0])  
    return (False , 0)

def fhouse(lst):
    if (lst[0][0] == lst[2][0] and lst[3][0] == lst[4][0]):
        return (True , lst[0][0] , lst[3][0])
    if (lst[0][0] == lst[1][0] and lst[2][0] == lst[4][0]):
        return (True , lst[2][0] , lst[0][0])
    return (False , 0)

def pair(lst , para):
    k = 1
    p = 0
    np = {}
    for i in range(3 , -1 , -1):
        if (lst[i][0] == lst[i + 1][0]):
            k += 1
        else:
            k = 1
        if (k == 2):
            p += 1
            np[p] = lst[i][0]
    if (para == 2 and p == 2):
        return (True , np[1] , np[2])
    if (para == 1 and p == 1):
        return (True , np[1])
    return (False , 0)

def doRank(player):
    t1 = straight(player)
    if ( t1[0] ):
        t2 = flush(player)
        if ( t2[0] ) :
            t3 = royal(player)
            if (t3[0]):
                rank = 10
            else:
                rank = (9 , t2[1])
        else:
            rank = (5 , t1[1])
    else:
        t4 = fok(player)
        t5 = fhouse(player)
        t6 = flush(player)
        t7 = tok(player)
        t8 = pair(player , 2)
        t9 = pair(player , 1) 
        if ( t4[0] ):
            rank = (8 , t4[1])
        elif ( t5[0] ):
            rank = (7 , t5[1] , t5[2])
        elif ( t6[0] ):
            rank = (6 , 1)
        elif (t7[0]):
            rank = (4 , t7[1])
        elif (t8[0]):
            rank = (3 , t8[1] , t8[2])
        elif (t9[0]):
            rank = (2 , t9[1])
        else:
            rank = (1 , 1)  

    return rank
ans = 0
li = 0
while True:
    line = f.readline()
    li += 1
    player1 = []
    player2 = []
   
    if (len(line)) == 0:
        break
    idx = 0
    for i in range(0,5):
        temp1 = (dic[line[idx]] , line[idx + 1])
        temp2 = (dic[line[idx + 15]] , line[idx  + 16])
        idx += 3
        player1.append(temp1)
        player2.append(temp2)
    player1.sort()
    player2.sort()
    print (player1 , '\n' , player2)
    r1 = doRank(player1)
    r2 = doRank(player2)
    pp = ans
    if (r1[0] > r2[0]):
        ans += 1
    elif (r1[0] == r2[0]):
        flag = 0
        for i in range(1 , len(r1)):
            if (r1[i] > r2[i]) :
                ans += 1
                flag = 1
                break
            elif r1[i] < r2[i]:
                flag = 1
                break;
        if (flag == 0):
            for i in range(4 , -1 , -1):
                if (player1[i][0] > player2[i][0]):
                    ans += 1
                    break
                elif player1[i][0] < player2[i][0]:
                    break         
    if (ans > pp):
        win = 'WIN'
    else:
        win = 'LOST'
    print (li , '  ' , win , '\n')
    print ('rank1: = ', r1 , '\nrank2: = ' , r2 , '\n' , ans) 
    print ('================================================\n')




