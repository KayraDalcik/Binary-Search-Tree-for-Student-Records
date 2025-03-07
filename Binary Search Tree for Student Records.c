#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int studentID;
    int grade;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int studentID, int grade) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->studentID = studentID;
    newNode->grade = grade;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int studentID, int grade) {
    if (root == NULL) {
        return createNode(studentID, grade);
    }
    if (studentID < root->studentID) {
        root->left = insertNode(root->left, studentID, grade);
    } else {
        root->right = insertNode(root->right, studentID, grade);
    }
    return root;
}

void printInOrder(TreeNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d %d\n", root->studentID, root->grade);
        printInOrder(root->right);
    }
}

void printTreeHelper(TreeNode* root, int parentGrade, char position) {
    if (root == NULL) {
        return;
    }

    if (position != 'N') {
        printf("%d %d (%d %c)\n", root->studentID, root->grade, parentGrade, position);
    } else {
        printf("%d %d\n", root->studentID, root->grade);
    }

    if (root->left) {
        printTreeHelper(root->left, root->grade, 'L');
    }

    if (root->right) {
        printTreeHelper(root->right, root->grade, 'R');
    }
}

void printTree(TreeNode* root) {
    printTreeHelper(root, -1, 'N');
}

int main() {
    TreeNode* root = NULL;
    int studentID, grade;

    while (scanf("%d", &studentID) && studentID != -1) {
        scanf("%d", &grade);
        root = insertNode(root, studentID, grade);
    }

    printInOrder(root);
    printTree(root);

    return 0;
}