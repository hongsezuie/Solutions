#include <QCoreApplication>
#include <solution.h>
#include <minstack.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Solution MySolution;

    TreeNode *root=new TreeNode(1);

    //root->left=new TreeNode(2);

    //root->left->left=new TreeNode(11);

    //root->left->left->left=new TreeNode(7);

    //root->left->left->right=new TreeNode(3);

    //root->right=new TreeNode(8);

    //root->right->left=new TreeNode(13);

    //root->right->right=new TreeNode(4);

    //root->right->right->right=new TreeNode(5);

    std::cout<<MySolution.hasPathSum(root,0)<<std::endl;

    return a.exec();
}


