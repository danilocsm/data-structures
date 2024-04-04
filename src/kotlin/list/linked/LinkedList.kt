package demo.list.linked

class LNode<T>(data: T) {
  var value = data
  var next: LNode<T>? = null
  var previous: LNode<T>? = null
}

class LinkedList<T>() {
  var head: LNode<T>? = null
  var tail: LNode<T>? = null
  var length: Int = 0

  fun insertFirst(data: T) {
    length++

    val newNode = LNode(data)

    if (head == null) {
      head = newNode
      tail = head
      return
    }
    head?.previous = newNode
    newNode.next = head
    head = newNode
  }

  fun removeFirst(): Boolean {
    if (head == null) return false

    val newHead = head?.next
    newHead?.previous = head?.previous
    head?.next = null
    head = newHead
    length--

    return true
  }

  fun insertLast(data: T) {
    length++

    val newNode = LNode(data)

    if (head == null) {
      head = newNode
      tail = head
      return
    }

    if (length == 1) {
      head?.next = newNode
      tail = newNode
      tail?.previous = head
      return
    }

    tail?.next = newNode
    newNode.previous = tail
    tail = newNode
  }

  fun removeLast(): Boolean {
    if (length == 0) return false

    length--
    if (length == 1) {
      head = null
      tail = head
      return true
    }

    val tailPrevious = tail?.previous
    tailPrevious?.next = tail?.next
    tail?.previous = null
    tail = tailPrevious

    return true
  }

  fun removeKey(key: T): Boolean {
    if (head == null) return false

    if (head?.value == key) {
      removeFirst()
      return true
    }

    if (tail?.value == key) {
      removeLast()
      return true
    }

    var current = head?.next
    while (current?.next != null) {
      if (current.value == key) {
        val currentPrevious = current.previous
        val currentNext = current.next
        currentPrevious?.next = current.next
        currentNext?.previous = current.previous
        current.next = null
        current.previous = null
        return true
      }

      current = current.next
    }

    return false
  }

  fun get(index: Int): T? {
    if (length == 0) return null

    if (index >= length) {
      return null
    }

    if (index < 0) {
      return null
    }

    if (index == 0) return head?.value

    if (index == length - 1) return tail?.value

    var i = 1
    var current = head?.next
    while (current != null) {
      if (i == index) return current.value
      i++
      current = current.next
    }

    return current?.value
  }

  fun head(): T? {
    if (head == null) return null
    return head?.value
  }

  fun tail(): T? {
    if (tail == null) return null
    return tail?.value
  }

  fun search(key: T): Boolean {
    if (length == 0) return false

    var current = head
    while (current != null) {
      if (current.value == key) return true
      current = current.next
    }
    return false
  }

  fun extend(list: LinkedList<T>) {
    if (head == null) {
      head = list.head
      tail = list.tail
      return
    }
    tail?.next = list.head
    list.head?.previous = tail
    tail = list.tail
    length += list.length
  }

  override fun toString(): String {
    var tempString = "[ "
    if (length == 0) return "[]"

    var current = head
    while (current != null) {
      tempString += current.value.toString() + " "
      current = current.next
    }
    tempString += "]"
    return tempString
  }
}
