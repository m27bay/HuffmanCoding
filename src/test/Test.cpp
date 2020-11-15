#include "Test.hpp"

Test::Test() : sumTest(0), numTestGlobal(0) {}

void Test::allTest() {
  /* Test Tree.hpp */
  std::cout << "########################### TESTS ##########################" << std::endl;
  std::cout << "#      test default builder 'sommet'        :" << (testDefaultBuilderSommet() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#     test builder 'sommet' with data       :" << (testBuilderSommetWithData() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#        test copy builder 'sommet'         :" << (testCopyBuilderSommet() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#      test default builder 'arbreB'        :" << (testDefaultBuilderArbreB() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#     test builder 'arbreB' with data       :" << (testBuilderArbreBWithData() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#        test copy builder 'arbreB'         :" << (testCopyBuilderArbreB() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#        test get 'sommet' at index         :" << (testGetSommetAtIndex() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                 test add                  :" << (testAdd() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                test dell                  :" << (testDell() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#               test depth                  :" << (testDepth() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                test size                  :" << (testSize() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                test find                  :" << (testFind() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#               test split                  :" << (testSplit() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                test join                  :" << (testJoin() ? "     passed"  : "       fail") << " ! #" << std::endl;
  /* Test Parser.hpp */
  // std::cout << "testCalculFreqChar : " << ((testCalculFreqChar()) ? "s ucced" : "fail") << " ! " << std::endl;
  
  std::cout << "################### ["<< sumTest << "/" << numTestGlobal << "] tests passed ! ###################" << std::endl;
}

/* Test Tree.hpp */
bool Test::testDefaultBuilderSommet() {
  Sommet node;

  bool ret = ( (node.getData() == 0)
          && (node.getLeft() == nullptr)
          && (node.getRight() ==  nullptr) );

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testDefaultBuilderArbreB() {
  ArbreB tree;

  bool ret = (tree.getRoot() == nullptr);

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testBuilderSommetWithData() {
  Sommet node(2);

  bool ret = ( (node.getData() == 2)
          && (node.getLeft() == nullptr)
          && (node.getRight() ==  nullptr) );

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testCopyBuilderSommet() {
  bool ret = 0;

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testBuilderArbreBWithData() {
  ArbreB tree(2);
  Sommet* root = tree.getRoot();

  bool ret = ( (root->getData() == 2)
          && (root->getLeft() == nullptr)
          && (root->getRight() ==  nullptr) );

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testCopyBuilderArbreB() {
  bool ret = 0;

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testGetSommetAtIndex() {
  ArbreB tree(1);

  tree << 2;
  tree << 3;
  tree << 4;

  Sommet* atPos = tree[3];

  bool ret = atPos->getData() == 2;

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testAdd() {
  ArbreB tree(2);
  tree << 3;
  
  bool ret = ( (tree.getRoot()->getLeft() && tree.getRoot()->getLeft()->getData() == 3)
              || (tree.getRoot()->getRight() && tree.getRoot()->getRight()->getData() == 3));
  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testDell() {
  bool ret = 0;

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testDepth() {
  ArbreB tree(1);

  tree << 2;
  tree << 3;
  tree << 4;

  bool ret = tree.getRoot()->getDepth() == 3;

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testSize() {
  ArbreB tree(1);

  tree << 2;
  tree << 3;
  tree << 4;

  bool ret = tree.getSize() == 4;

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testFind() {
  ArbreB tree(1);

  tree << 2;
  tree << 3;
  tree << 4;

  Sommet* tryFind = tree.find(tree.getRoot(), 3);
  Sommet* tryFind2 = tree.find(tree.getRoot(), 0); 

  bool ret = (tryFind->getData() == 3 && !tryFind2);

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}

bool Test::testSplit() {
  bool ret = 0;

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}

bool Test::testJoin() {
  bool ret = 0;

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}
/* End Tree.hpp */

/* Test Parser.hpp */
bool Test::testCalculFreqChar() {
  std::vector<int> freq = {'h', 1, 'e', 1, 'l', 3, 'o', 2, ' ', 1, 'w', 1, 'r', 1, 'd', 1};

  Parser parser;
  std::vector<int> freq2;
  parser.freqChar("textTest.txt", freq2);

  for(int i = 0; i < 9; ++i) {
    if(freq[i] != freq2[i]) {
      return false;
    }
  }
  return true;
}
/* End Parser.hpp */