import pandas as pd
z=int(0)
file = input('enter file: ')
file=file+'.xlsx'
df = pd.read_excel(file)
Q=input('Do you want to see it all?: ')
if(Q=="yes" or Q=="Yes"):
    for ind,row in df.iterrows():
        print(ind,row)
else:
    Aw=input('Which one do you want to look at?: ')
    print('')
    a=Aw
    for i in df:
        z=df.at[int(a), i]
        print(i,':',z)
