/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

class BTNode
{
  char m_item;
  BTNode *m_left;
  BTNode *m_right;

public:
    BTNode ()
  {
    m_left = NULL;
    m_right = NULL;
  }
  void setItem (char letter)
  {
    m_item = letter;
  }
  char getItem ()
  {
    return m_item;
  }
  void setLeft (BTNode * left)
  {
    m_left = left;
  }
  BTNode *getLeft ()
  {
    return m_left;
  }
  void setRight (BTNode * right)
  {
    m_right = right;
  }
  BTNode *getRight ()
  {
    return m_right;
  }

};

void
postOrderPrint (BTNode * root)
{
  if (root == NULL)
    return;

  postOrderPrint (root->getLeft ());
  postOrderPrint (root->getRight ());
  cout << root->getItem () << " ";
}

BTNode *
makeArithmeticExpressionTree (string postfix)
{
  stack < BTNode * >myStack;

  for (int i = 0; i < postfix.size (); i++)
    {
      if (postfix[i] == 'A' || postfix[i] == 'B' || postfix[i] == 'C'
	  || postfix[i] == 'D' || postfix[i] == 'E' || postfix[i] == 'F'
	  || postfix[i] == 'G')
	{
	  BTNode *myPointer = new BTNode;
	  myPointer->setItem (postfix[i]);
	  myStack.push (myPointer);

	}

      if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*'
	  || postfix[i] == '/')
	{
	  BTNode *myPointer2 = new BTNode;
	  myPointer2->setItem (postfix[i]);
	  BTNode *p1;
	  p1 = myStack.top ();
	  myStack.pop ();
	  BTNode *p2;
	  p2 = myStack.top ();
	  myStack.pop ();
	  myPointer2->setLeft (p2);
	  myPointer2->setRight (p1);
	  myStack.push (myPointer2);

	}
    }

  return myStack.top ();
}

int
main ()
{

  ifstream inFile;
  inFile.open ("input.txt");
  if (!inFile)
    {
      cout << "Unable to open file datafile.txt";
      exit (1);
    }

  while (!inFile.eof ())
    {
      string line;
      BTNode *final;
      getline (inFile, line);
      cout << "Original:  " << line << endl;
      final = makeArithmeticExpressionTree (line);
      cout << "Traversed: ";
      postOrderPrint (final);
      cout << endl;
      cout << endl;
    }

  inFile.close ();

  return 0;
}
