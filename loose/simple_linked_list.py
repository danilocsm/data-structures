class Node(object):

    def __init__(self,data=None,next=None):
        self.data = data
        self.next = next

    def __str__(self):

        return "DATA : {}.".format(self.data)


class LinkedList(object):

    def __init__(self,head=None):

        self.head = head

    def show_list(self):

        aux = self.head
        while aux != None:
            print(aux)
            aux = aux.next

        # print(aux)

    def insert_item_last(self,node):

        if self.head is None:
            self.head = node
        else:
            aux = self.head
            while(aux.next != None):
                aux = aux.next
            aux.next = node


    def insert_item_first(self,node):

        if self.head is None:
            self.data = item
        else:
            node.next = self.head
            self.head = node

    def remove_item(self,key):

        if self.head is None:
            return None
        else:
            prev = None
            aux = self.head
            found = False
            while aux is not None:

                if aux.data == key:
                    found = True
                    break

                prev = aux
                aux = aux.next

            if found:
                if prev is not None:
                    prev.next = aux.next

                else:
                    self.head = aux.next

                del aux


    def search_item(self,key):

        if self.head is None:
            return False
        else:
            aux = self.head
            while aux.next is not None:
                if aux.data == key:
                    return True
                else:
                    aux = aux.next

            if aux.data == key:
                return True

            return False

my_list = LinkedList()


my_list.insert_item_last(Node(3))
my_list.insert_item_last(Node(4))
my_list.insert_item_last(Node(5))
my_list.insert_item_first(Node(1))
print("Lista")
my_list.show_list()
my_list.remove_item(5)
my_list.show_list()
print(my_list.head)
if my_list.search_item(5):
    print("Achou")
else:
    print("Nao achou")
