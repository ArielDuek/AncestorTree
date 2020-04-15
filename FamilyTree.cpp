#include "FamilyTree.hpp"
#include <iostream>
using namespace family;

Tree& Tree::addFather(string name, string father){
    add(this->root,name,father,0,1);
    return *this;
}

Tree& Tree::addMother(string name, string mother){
    add(this->root,name,mother,1,1);
    return *this;
}
string Tree::relation(string name){
    if(this->root->getName()==name) return "me";
    if(this->root->getMother()->getName()==name) return "mother";
    if(this->root->getFather()->getName()==name) return "father";
    string toReturn = "";
    string temp = "great-";
    int height =-1;
    int gander =-1;
    relationFind(this->root,name,&height,&gander);
    if(height==-1 && gander==-1) return "unrelated";
    for (int i = height; i>2 ; i--) {
        toReturn=temp+toReturn;
    }
    if(gander==0){
        toReturn = toReturn+"grandfather";
    }
    else toReturn = toReturn+"grandmother";

    return toReturn;

}
string Tree::find(string name){
    if(name=="me") return this->root->getName();
    if(name=="mother") return this->root->getMother()->getName();
    if(name=="father") return this->root->getFather()->getName();
    string temp ="";
    string& ans=temp;
    findRec(this->root, name,ans);
    if(ans=="")
        throw runtime_error("Didnt found in tree");
    return ans;

}
void Tree::remove(string name){

}
void Tree::display(){

}

void add(Node* root ,string name, string toAdd,int gander,int height){
    if(root==NULL) return;
    if(gander==0 && root->getName()==name && root->getFather()==NULL){
        root->setNode(toAdd,gander,height);
        return;
    }
    if(gander==1 && root->getName()==name && root->getMother()==NULL){
        root->setNode(toAdd,gander,height);
        return;
    }
    if(root!=NULL){
        add(root->getMother(), name, toAdd, gander,height+1);
        add(root->getFather(), name, toAdd, gander,height+1);
    }
}

void relationFind(Node * root, string name,int* height,int* gander){
    if(root==NULL) return;
    if(root->getName()==name){
        *(height)=root->getHeight();
        *(gander)=root->getGander();
        return;
    }
    relationFind(root->getMother(), name,height,gander);
    relationFind(root->getFather(), name,height,gander);
}

void findRec(Node * root, string name,string &ans) {
    if (name == "grandmother" && root->getMother()->getMother() != NULL) {
        ans = root->getMother()->getMother()->getName();
        return;
    } else if (name == "grandmother" && root->getFather()->getMother() != NULL) {
        ans = root->getFather()->getMother()->getName();
        return;
    } else if (name == "grandfather" && root->getFather()->getFather() != NULL) {
        ans = root->getFather()->getFather()->getName();
        return;
    } else if (name == "grandfather" && root->getMother()->getFather() != NULL) {
        ans = root->getMother()->getFather()->getName();
        return;
    }
    if((name!="grandmother" && name!="grandfather") && (name.length()<6 || name.substr(0,6)!="great-")) throw runtime_error("Didnt found in tree");
    if((name!="grandmother" && name!="grandfather"))findRec(root->getFather(), name.substr(6), ans);
    if((name!="grandmother" && name!="grandfather")&& ans=="")findRec(root->getMother(), name.substr(6), ans);
}