from collections import deque
class BinarySearchTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    def add_child(self, data):
        if data== self.data:
            return
        if data < self.data:
            #add data to left sub tree
            if self.left:
                self.left.add_child(data)
            else:
                self.left =  BinarySearchTreeNode(data)
        else:
            #add data to right sub tree
            if self.right:
                self.right.add_child(data)
            else:
                self.right = BinarySearchTreeNode(data)

    #sorting
    def return_inorder_list(self):                               #In order traversal
        elements = []
        if self.left:
            elements += self.left.return_inorder_list()
        elements.append(self.data)
        if self.right:
            elements+=self.right.return_inorder_list()
        return elements
    def return_preorder_list(self):                              #Pre order traversal
        elements = []
        elements.append(self.data)
        if self.left:
            elements += self.left.return_preorder_list()
        if self.right:
            elements+=self.right.return_preorder_list()
        return elements
    def return_postorder_list(self):                             #Post order traversal
        elements = []
        if self.left:
            elements += self.left.return_postorder_list()
        if self.right:
            elements+=self.right.return_postorder_list()
        elements.append(self.data)
        return elements

    def return_levelorder_list(self, elements=[]):

        queue = [self] if self else []

        while queue:
            node = queue.pop()
            elements.append(node.data)

            if node.left: queue.insert(0, node.left)
            if node.right: queue.insert(0, node.right)
        return elements

    def search_the_existence_of_an_element_in_the_list(self, Value):     #If the passed value is in the list of items within the BST, this method will return true, else false
        if self.data==Value:
            return True
        elif self.data>Value and self.left:
            return self.left.search_the_existence_of_an_element_in_the_list(Value)
        elif self.data<Value and self.right:
            return self.right.search_the_existence_of_an_element_in_the_list(Value)
        return False

    def getHeight(self,root):
    #Write your code here
        if root == None:
            return -1
        return 1 + max(self.getHeight(root.left), self.getHeight(root.right))




def build_tree(elements):
    root = BinarySearchTreeNode(elements[0])
    for i in range(1,len(elements)):
        root.add_child(elements[i])
    return root







LIST =[25,15,10,4,12,22,18,24,50,35,31,44,70,66,90]

BST =build_tree(LIST)



IN_ORDER = BST.return_inorder_list()
PRE_ORDER = BST.return_preorder_list()
POST_ORDER = BST.return_postorder_list()
LEVEL_ORDER= BST.return_levelorder_list()
print(IN_ORDER)
print(PRE_ORDER)
print(POST_ORDER)
print(LEVEL_ORDER)

print(BST.search_the_existence_of_an_element_in_the_list(50))

print(BST.getHeight(BST))

print()
