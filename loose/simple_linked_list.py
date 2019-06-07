class Node(object):

    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next

    def __str__(self):
        return "DATA : {}.".format(self.data)

class LinkedList(object):

    def __init__(self, head = None):
        self.head = head

    def show_list(self):
        aux = self.head
        while aux:
            print(aux)
            aux = aux.next

    def insert_item_last(self, item):
        if not self.head:
            self.head = Node(item)
        else:
            aux = self.head
            while aux.next:
                aux = aux.next
            aux.next = Node(item)

    def insert_item_first(self, item):
        if not self.head:
            self.head = Node(item)
        else:
            new_node = Node(item)
            new_node.next = self.head
            self.head = new_node

    def remove_item_first(self):
        if not self.head:
            return None
        else:
            aux = self.head
            self.head = aux.next
            del aux

    def remove_item_last(self):
        if not self.head:
            return None
        else:
            aux = self.head
            prev = None
            while aux.next:
                prev = aux
                aux = aux.next
            if prev == None:
                self.head = None
            else:
                prev.next = aux.next
            del aux

    def remove_item(self, key):
        if self.head:
            return None
        else:
            prev = None
            aux = self.head
            found = False
            while aux:
                if aux.data == key:
                    found = True
                    break
                prev = aux
                aux = aux.next
            if found:
                if prev:
                    prev.next = aux.next
                else:
                    self.head = aux.next
                del aux

    def search_item(self, key):
        if self.head:
            return False
        else:
            aux = self.head
            while aux.next:
                if aux.data == key:
                    return True
                else:
                    aux = aux.next
            if aux.data == key:
                return True
            return False
