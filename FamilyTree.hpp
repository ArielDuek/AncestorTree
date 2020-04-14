//#pragma once
#include <string>
using namespace std;

class Node{
    string name;
    Node * father;
    Node * mother;
    int gander;
    int height;

public:
    Node (string name,int gander,int height){
        this->name=name;
        this->father=NULL;
        this->mother=NULL;
        this->gander=gander;
        this->height=height;
    }
    string getName(){
        return this->name;
    }
    Node* getMother(){
        return this->mother;
    }
    Node* getFather(){
        return this->father;
    }
    int getGander(){
        return this->gander;
    }
    int getHeight(){
        return this->height;
    }
    void setNode (string toAdd,int gander,int height){
        if(gander == 0) {
            Node *ans = new Node(toAdd,gander,height);
            this->father = ans;
        }
        else{
            Node* ans = new Node(toAdd,gander,height);
            this->mother=ans;
        }
    }
};

namespace family{
    class Tree {
        Node* root;
    public:
        Tree(string name) { this->root = new Node(name,0,0); }

        Tree& addFather(string name, string father);

        Tree& addMother(string name, string mother);

        string relation(string name);

        string find(string name);

        void remove(string name);

        void display();

        Node* getNode(){
            return this->root;
        }

        Tree& getTree() {
            return *this;
        }
    };
}
void addInOrder(Node* root,string name,string toAdd,int gander,int height);

void relationFind(Node * root, string name,int* height,int* gander);

void findRec(Node * root, string name,string& ans);