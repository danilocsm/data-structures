# Código básico com a implementação de uma árvore binária de pesquisa.
# Implementação da inserção,remoção e busca de um elemento em uma árvore binária.

class BinaryTree(object):

	def __init__(self,data=None,left=None,right=None):

		self.data = data
		self.left = left
		self.right = right

	'''
	def __str__(self):

		return print("{0}<----{1}---->{2}".format(self.left.data,self.data,self.right.data))
	'''

	def insert(root,node):

		if root is None:
			root = node
		elif root.data < node.data:
			if root.right is None:
				root.right = node
			else:
				BinaryTree.insert(root.right,node)
		else:
			if root.left is None:
				root.left = node
			else:
				BinaryTree.insert(root.left,node)

	def search(root, key):

		if root is None:
			return False

		if root.data == key:
			return True

		if root.data < key:
			return BinaryTree.search(root.right,key)

		else:
			return BinaryTree.search(root.left,key)

	def remove(root,key):

		if root is None:
			return None
		else:
			if key > root.data:
				root.right = BinaryTree.remove(root.right,key)
			elif key < root.data:
				root.left =	BinaryTree.remove(root.left,key)
			else:

				if root.right is None and root.left is None:
					del(root.data)
					root = None
				elif root.right is None and root.left is not None:
					del(root.data)
					aux = root
					root = root.left
					del aux
				elif root.right is not None and root.left is None:
					del(root.data)
					aux = root
					root = root.right
					del aux
				elif root.right is not None and root.left is not None:
					aux = root.left
					while aux.right != None:
						aux = aux.right
					root.data = aux.data
					aux.data = key
					root.left = BinaryTree.remove(root.left,key)

		return root

	def in_order(root):

		if root != None:
			BinaryTree.in_order(root.left)
			print(root.data)
			BinaryTree.in_order(root.right)

root = BinaryTree(None)
BinaryTree.insert(root,BinaryTree(4))
BinaryTree.insert(root,BinaryTree(6))
BinaryTree.insert(root,BinaryTree(5))
BinaryTree.insert(root,BinaryTree(2))
BinaryTree.in_order(root)
root = BinaryTree.remove(root,4)
BinaryTree.in_order(root)
