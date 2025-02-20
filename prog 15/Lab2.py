s1=input("Enter string 1 : ")
s2=input("Enter string 2 : ")
s=s2[0]+s1[1:]+" "+s1[0]+s2[1:]
print("New string : ",s)
clr=input("Enter colors seperated by  commas : ")
c=clr.split(",")
print("Alternate colors : ",c[::2])
