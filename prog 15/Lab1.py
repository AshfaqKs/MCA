s=input("Enter a string : ")
n=s.replace(s[0],"$")
n=s[0]+n[1:]
print("New string : ",n)
print("Exchanged string : ",s[-1]+s[1:-1]+s[0])
      
