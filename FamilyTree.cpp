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
    if(name=="mother" && this->root->getMother()!=NULL) return this->root->getMother()->getName();
    if(name=="father" && this->root->getFather()!=NULL) return this->root->getFather()->getName();
    string temp ="";
    string& ans=temp;
    findRec(this->root, name,ans);
    if(ans=="")
        throw runtime_error("Didnt found in tree");
    return ans;

}






void Tree::remove(string name){
    Node * child = NULL;
    if (this->root->getName() == name) throw runtime_error("Cant delete the root");
    else findToDelete (this->root, name, &child);
    if (child == NULL) throw runtime_error("Didnt found in the tree");
    else {
        if (child->getMother()!=NULL && child->getMother()->getName() == name) {
            deleteSubTree(child->getMother());
            child->setMotherNull();
        }
        else if (child->getFather()!=NULL && child->getFather()->getName() == name) {
            deleteSubTree (child->getFather());
            child->setFatherNull();
        }
    }
}

void findToDelete (Node * root, string name, Node ** child){
    if (root == NULL) return;
    if((root->getMother()!=NULL && root->getMother()->getName()==name )||(root->getFather()!=NULL && root->getFather()->getName()==name)){
        *(child) = root;
        return;
    }
    if (root->getFather() != NULL) findToDelete (root->getFather(), name, child);
    if (root->getMother() != NULL) findToDelete (root->getMother(), name, child);
}

void deleteSubTree(Node* root){
    if(root!= NULL){
        deleteSubTree(root->getFather());
        deleteSubTree(root->getMother());
        delete root;
    }
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
    if(root==NULL) return;
    if (root->getMother()!=NULL && name == "grandmother" && root->getMother()->getMother() != NULL) {
        ans = root->getMother()->getMother()->getName();
        return;
    } else if ( root->getFather()!=NULL && name == "grandmother" && root->getFather()->getMother() != NULL) {
        ans = root->getFather()->getMother()->getName();
        return;
    } else if (root->getFather()!=NULL && name == "grandfather" && root->getFather()->getFather() != NULL) {
        ans = root->getFather()->getFather()->getName();
        return;
    } else if (root->getMother()!=NULL && name == "grandfather" && root->getMother()->getFather() != NULL) {
        ans = root->getMother()->getFather()->getName();
        return;
    }
    if((name!="grandmother" && name!="grandfather") && (name.length()<6 || name.substr(0,6)!="great-")) throw runtime_error("The tree cannot handle this relation");
    if((name!="grandmother" && name!="grandfather"))findRec(root->getFather(), name.substr(6), ans);
    if((name!="grandmother" && name!="grandfather")&& ans=="")findRec(root->getMother(), name.substr(6), ans);
}

