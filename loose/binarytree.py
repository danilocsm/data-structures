# Código básico com a implementação de uma árvore binária de pesquisa.
# Implementação da inserção,remoção e busca de um elemento em uma árvore binária.

class Node(object):

    def __init__(self,data = None, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right

class BinaryTree(object):

    def __init__(self, root = None):
        self.root = root

    def insert(self,item):
        self.root = self.aux_insert(self.root, item)

    def aux_insert(self, root, item):

        if root is None:
            root = Node(item)
        elif root.data > item:
            root.left = self.aux_insert(root.left, item)
        elif root.data < item:
            root.right = self.aux_insert(root.right, item)

        return root

    def remove(self, key):
        self.root = self.aux_remove(self.root, key)

    def aux_remove(self, root, key):
        if not root:
            return None
        elif key > root.data:
            root.right = self.aux_remove(root.right, key)
        elif key < root.data:
            root.left = self.aux_remove(root.left, key)
        else:
            if not root.right and not root.left:
                del root
                root = None
            elif not root.right and root.left:
                aux = root
                root = root.left
                del aux
            elif root.right and not root.left:
                aux = root
                root = root.right
                del aux
            else:
                aux = root.left
                while aux.right:
                    aux = aux.right
                root.data = aux.data
                aux.data = key
                root.left = self.aux_remove(root.left, key)

        return root

    def search(self, key):
        return self.aux_search(self.root, key)

    def aux_search(self, root, key):
        if not root:
            return False
        elif key > root.data:
            return self.aux_search(root.right, key)
        elif key < root.data:
            return self.aux_search(root.left, key)
        else:
            return True

    def in_order(self):
        self.aux_in_order(self.root)

    def aux_in_order(self, root):
        if root != None:
            self.aux_in_order(root.left)
            print(root.data)
            self.aux_in_order(root.right)

