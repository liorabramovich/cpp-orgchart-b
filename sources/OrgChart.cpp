#include "OrgChart.hpp"
#include <string>
#include "queue"
#include "stack"
#include "algorithm"
using namespace std;
using namespace ariel;

Node::Node(const std::string &data) { this->data = data;this->parent=nullptr; }

OrgChart::OrgChart(const OrgChart &org){

    this->root = new Node(org.root->get_data());
    All_P.push_back(this->root);
    for(Node *p : org.All_P){
        if(p->get_parent()!=nullptr){

        this->add_sub(p->get_parent()->get_data(),p->get_data());
        }
    }
}

OrgChart::OrgChart(OrgChart && org)noexcept{
    this->root = org.root;
}

OrgChart& OrgChart::operator=(const OrgChart &org){

        if(this!=&org){
            this->root = new Node(org.root->get_data());
            All_P.push_back(root);
        for(Node *p : org.All_P){
            this->add_sub(p->get_parent()->get_data(),p->get_data());
        }
            }
    return *this;
}

OrgChart& OrgChart::operator=(OrgChart &&org) noexcept{ *this = move(org);

return *this;}

OrgChart::OrgChart() { this->root = nullptr; }

OrgChart::~OrgChart() {
    for(Node *p : this->All_P ){delete p;}}

OrgChart &OrgChart::add_root(const std::string &root_data)
{
    if (root_data.empty())
    {
        throw runtime_error("name must have at least 1 character");
    }
    if( root != nullptr){
        this->root->set_data(root_data);

    }
    else{
        this->root = new Node(root_data);
        root->set_parent(nullptr);
        this->All_P.push_back(root);
    }

    return *this;
}

OrgChart &OrgChart::add_sub(const std::string &parent, const std::string &child)
{
    for (Node *ch : this->All_P)
    {
        if (ch->get_data() == parent)
        {
            Node *NewChild = new Node(child);
            ch->Add_to_son_vec(NewChild);
            NewChild->set_parent(ch);
            this->All_P.push_back(NewChild);
            return *this;
        }
    }
    throw runtime_error(" Parent does not exist");
}

void OrgChart::BFS(Node *root)
{
    queue<Node *> queue;

    queue.push(root);
    while (!queue.empty())
    {
        int size = queue.size();
        while(size > 0 ){
        Node *ToIter = queue.front();
        Res.push_back(ToIter->get_data());
        queue.pop();
        for (unsigned int i = 0; i < ToIter->children().size(); i++)
        {
            queue.push(ToIter->children().at(i));
        }
        size--;
        }
    }
}

void OrgChart::DFS(Node *root)
{
    Res.push_back(root->get_data());
    for (Node *p : root->children())
    {
        if (!p->get_visited())
        {
            DFS(p);
        }
    }
}

void OrgChart::Reverse(Node *root)
{
    vector<Node *> vec;

    vec.push_back(root);
    while (!vec.empty())
    {
        int s = vec.size();
        while(s>0){
        Node *ToIter = vec.front();
        Res.push_back(ToIter->get_data());
        vec.erase(vec.begin());
        for (unsigned int i = ToIter->children().size(); i > 0; --i)
        {
            vec.push_back(ToIter->children()[i - 1]);
        }
        s--;
        }
    }
    reverse(Res.begin(), Res.end());
}

std::string *OrgChart::begin_level_order(){if (root == nullptr){throw runtime_error("chart is empty!");}Res.clear();this->BFS(root);return &this->Res[0];}
std::string *OrgChart::end_level_order(){if (root == nullptr){throw runtime_error("chart is empty!");}Res.clear();this->BFS(root);return &this->Res[Res.size()];}

std::string *OrgChart::begin_reverse_order(){if (root == nullptr){throw runtime_error("chart is empty!");}Res.clear();this->Reverse(root);return &this->Res[0];}
std::string *OrgChart::reverse_order(){if (root == nullptr){throw runtime_error("chart is empty!");}Res.clear();this->Reverse(root);return &this->Res[Res.size()];}

std::string *OrgChart::begin_preorder(){if (root == nullptr){throw runtime_error("chart is empty!");}Res.clear();this->DFS(root);return &this->Res[0];}
std::string *OrgChart::end_preorder(){if (root == nullptr){throw runtime_error("chart is empty!");}Res.clear();this->DFS(root);return &this->Res[Res.size()];}

std::string *OrgChart::begin(){if (root == nullptr){throw runtime_error("chart is empty!");}Res.clear();this->BFS(root);return &this->Res[0];}
std::string *OrgChart::end(){if (root == nullptr){throw runtime_error("chart is empty!");}Res.clear();this->BFS(root);return &this->Res[Res.size()];}

namespace ariel
{

    std::ostream &operator<<(std::ostream &out, OrgChart &Chart)
    {
        std::string res = " ";
        for (Node *temp : Chart.All_P)
        {
            res+=temp->get_data() + " ";
        }
        return out<<res;
    }

}