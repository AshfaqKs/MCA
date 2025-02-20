list1=['red','blue','black','yellow','white']
list2=['purple','white','black','green']
print("list 1 : ",list1)
print("list 2 : ",list2)
print("Colors only in list 1 : ",set(list1)-set(list2))
list3=['a','b','c','a','b','d']
print("list 3 : ",list3)
print("List after removing duplicates : ",set(list3))
list4=[]
print("list 4 : ",list4)
print("list 4 is empty : ",bool(not(len(list4))))
