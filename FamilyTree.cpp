#include "FamilyTree.hpp"
#include <iostream>
using namespace family;

Tree& Tree::addFather(string name, string father){
    bool af = add(this->root,name,father,0,1);
    if(!af) throw runtime_error("Cant add to the tree.");
    return *this;
}

Tree& Tree::addMother(string name, string mother){
    bool am = add(this->root,name,mother,1,1);
    if(!am) throw runtime_error("Cant add to the tree.");
    return *this;
}
string Tree::relation(string name){
    if(this->root->getName()==name) return "me";
    if(this->root->getMother()!=NULL && this->root->getMother()->getName()==name) return "mother";
    if(this->root->getFather()!=NULL && this->root->getFather()->getName()==name) return "father";
    string toReturn = "";
    string temp = "great-";
    int height =-1;
    int gander =-1;
    relationRec(this->root,name,&height,&gander);
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
    if (this->root->getName() == name) throw runtime_error("Cant delete root");
    else deleteFromTree (this->root, name);
}

void Tree::display(){

}

bool add(Node* root ,string name, string toAdd,int gander,int height){
    if(root==NULL) return false;
    if(root->getName()==name){
        if ((gander==0 && root->getFather()==NULL) ||
            (gander==1 && root->getMother()==NULL)){
            root->setNode(toAdd, gander, height);
            return true;
        } else return false;
    }
    else{
        bool a = add(root->getMother(), name, toAdd, gander,height+1);
        bool b = add(root->getFather(), name, toAdd, gander,height+1);
        return  a || b;
    }
}

void relationRec(Node * root, string name,int* height,int* gander){
    if(root==NULL) return;
    if(root->getName()==name){
        *(height)=root->getHeight();
        *(gander)=root->getGander();
        return;
    }
    relationRec(root->getMother(), name,height,gander);
    relationRec(root->getFather(), name,height,gander);
}

void findRec(Node * root, string name, string &ans) {
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

void deleteFromTree (Node * root, string name){
    if (root->getName() == name) {
        root = NULL;
    }
    else if ((root->getFather() != NULL) || (root->getMother() != NULL)){
        if (root->getFather() != NULL) deleteFromTree (root->getFather(), name);
        if (root->getMother() != NULL) deleteFromTree (root->getMother(), name);
    }
    else throw runtime_error("Didnt found in the tree");
}