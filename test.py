class Shoe:
    def populate(self):
        self.id=input("Enter ID: ") 
        self.brand=input("Enter Brand: ") 
        self.colour=input("Enter colour: ")
        self.size=input("Enter size: ") 
        self.price=input("Enter price: ") 
        self.style=input("Enter style: ") 
        
        with open("shoe.txt","a") as file:
            file.write("{} {} {} {} {} {}\n".format(self.id, self.brand, self.colour, self.size, self.price, self.style))
        print("\nRecord Added!\n")

    def display_all(self):
        with open("shoe.txt","r") as file:
            data = file.readlines()
            for i in data:
                i = i.split()
                print("Shoe ID: {}\nShoe Brand: {}\nShoe Colour: {}\nShoe Size: {}\nShoe Price: {}\nShoe Style: {}".format(*i))
                print()

    def update_record(self,id):
        data = []
        with open("shoe.txt","r") as file:
            data = file.readlines()
        for i in range(len(data)):
            if data[i].split()[0] == id:
                shoe = data[i].split()
                c = int(input("Enter 1 to modify Brand, 2 to modify Colour, 3 to modify Size, 4 to modify Price, 5 to modify Style: "))
                shoe[c] = input("Enter new value: ")
                str = ""
                for j in shoe:
                    str+= j+" "
                str+= "\n"
                data[i] = str

        with open("shoe.txt","w") as file:
            file.writelines(data)
        print("Record Updated")

    def delete_record(self,id):
        data = []
        with open("shoe.txt","r") as file:
            data = file.readlines()
        for i in data:
            if i.split()[0] == id:
                data.remove(i)
        with open("shoe.txt","w") as file:

            file.writelines(data)
        print("Record Removed")
        
while True:
    print("Press 1 to add a new shoe")
    print("Press 2 to read all shoe details")
    print("Press 3 to update shoe details")
    print("Press 4 to delete an entry")
    print("Press 5 to exit")
    choice = int(input("Choice: "))
    print()
    if choice == 1:
        newShoe = Shoe()
        newShoe.populate() 

    elif choice == 2:
        print("\nCurrent Records\n")
        Shoe().display_all()

    elif choice == 3:
        id = input("Enter Shoe ID: ")
        Shoe().update_record(id)

    elif choice == 4:
        id = input("Enter Shoe ID: ")
        Shoe().delete_record(id)

    elif 5:
        break



