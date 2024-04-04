package demo.tree.binary

class TNode<T>(data: T) {
  var right: TNode<T>? = null
  var left: TNode<T>? = null
  var value: T = data
  var height: Int = 1
}

class BST<T> {
  private var root: TNode<T>? = null

  fun root(): T? {
    return root?.value
  }

  private fun max(a: Int, b: Int): Int {
    if (a > b) return a else return b
  }

  private fun height(root: TNode<T>?): Int {
    if (root == null) return 0
    return root.height
  }

  private fun getBalance(root: TNode<T>?): Int {
    if (root == null) return 0
    return height(root.left) - height(root.right)
  }

  private fun rotateLeft(root: TNode<T>?): TNode<T>? {
    var rootRight = root?.right
    var rootRightLeft = rootRight?.left
    rootRight?.left = root
    root?.right = rootRightLeft
    root?.height = max(height(root?.left), height(root?.right)) + 1
    rootRight?.height = max(height(rootRight?.left), height(rootRight?.right)) + 1

    return rootRight
  }

  private fun rotateRight(root: TNode<T>?): TNode<T>? {
    var rootLeft = root?.left
    var rootLeftRight = rootLeft?.right
    rootLeft?.right = root
    root?.left = rootLeftRight
    root?.height = max(height(root?.left), height(root?.right)) + 1
    rootLeft?.height = max(height(rootLeft?.left), height(rootLeft?.right)) + 1

    return rootLeft
  }

  private fun insertRecursive(
      currentNode: TNode<T>?,
      data: T,
      cmpFn: (a: T, b: T) -> Int,
      isRebalance: Boolean = false
  ): TNode<T>? {
    if (currentNode == null) return TNode(data)
    else if (cmpFn(currentNode.value, data) < 0)
        currentNode.right = insertRecursive(currentNode.right, data, cmpFn)
    else if (cmpFn(currentNode.value, data) > 0)
        currentNode.left = insertRecursive(currentNode.left, data, cmpFn)

    if (!isRebalance) {
      return currentNode
    }

    val balance = getBalance(currentNode)

    when {
      balance > 1 && cmpFn(currentNode.left!!.value, data) > 0 -> {
        return rotateRight(currentNode)
      }
      balance < -1 && cmpFn(currentNode.right!!.value, data) <= 0 -> {
        return rotateLeft(currentNode)
      }
      balance > 1 && cmpFn(currentNode.left!!.value, data) <= 0 -> {
        currentNode.left = rotateLeft(currentNode.left)
        return rotateRight(currentNode)
      }
      balance < -1 && cmpFn(currentNode.right!!.value, data) > 0 -> {
        currentNode.right = rotateRight(currentNode.right)
        return rotateLeft(currentNode)
      }
      else -> return currentNode
    }
  }

  fun insertBalanced(data: T, cmpFn: (a: T, b: T) -> Int) {
    root = insertRecursive(root, data, cmpFn, true)
  }

  fun insert(data: T, cmpFn: (a: T, b: T) -> Int) {
    root = insertRecursive(root, data, cmpFn)
  }

  private fun removeRecursive(
      currentNode: TNode<T>?,
      data: T,
      cmpFn: (a: T, b: T) -> Int,
      isRebalance: Boolean = false
  ): TNode<T>? {
    if (currentNode == null) return null
    else if (cmpFn(currentNode.value, data) < 0)
        currentNode.right = removeRecursive(currentNode.right, data, cmpFn)
    else if (cmpFn(currentNode.value, data) > 0)
        currentNode.left = removeRecursive(currentNode.left, data, cmpFn)
    else {
      when {
        currentNode.left == null && currentNode.right == null -> {
          return null
        }
        currentNode.right == null && currentNode.left != null -> {
          return currentNode.left
        }
        currentNode.right != null && currentNode.left == null -> {
          return currentNode.right
        }
        currentNode.right != null && currentNode.left != null -> {
          var aux = currentNode.left
          while (aux?.right != null) aux = aux.right
          currentNode.value = aux!!.value
          aux.value = data
          currentNode.left = removeRecursive(currentNode.left, data, cmpFn)
        }
      }
    }

    if (!isRebalance) {
      return currentNode
    }

    currentNode.height = max(height(currentNode.left), height(currentNode.right)) + 1
    val balance = getBalance(currentNode)

    when {
      balance > 1 && getBalance(currentNode.left) >= 0 -> {
        return rotateRight(currentNode)
      }
      balance > 1 && getBalance(currentNode.left) < 0 -> {
        currentNode.left = rotateLeft(currentNode.left)
        return rotateRight(currentNode)
      }
      balance < -1 && getBalance(currentNode.right) <= 0 -> {
        return rotateLeft(currentNode)
      }
      balance < -1 && getBalance(currentNode.right) > 0 -> {
        currentNode.right = rotateRight(currentNode.right)
        return rotateLeft(currentNode)
      }
      else -> return currentNode
    }
  }

  fun removeBalanced(data: T, cmpFn: (a: T, b: T) -> Int) {
    root = removeRecursive(root, data, cmpFn, true)
  }

  fun remove(data: T, cmpFn: (a: T, b: T) -> Int) {
    root = removeRecursive(root, data, cmpFn)
  }

  fun transverseRecursive(currentNode: TNode<T>?) {
    if (currentNode == null) return
    transverseRecursive(currentNode.left)
    println(currentNode.value)
    transverseRecursive(currentNode.right)
  }

  fun transverse() {
    transverseRecursive(root)
  }
}
