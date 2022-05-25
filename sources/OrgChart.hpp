#include <string>
#include <iostream>
#include "vector"

namespace ariel
{
    class Node
    {
        private:
            std::string data;
            std::vector<Node*> son;
            bool visited = false;
            Node *parent;

        public:
            Node(const std::string &data);
            void set_data(const std::string &data){this->data = data;}
            std::string get_data(){return this->data;}
            void Add_to_son_vec(Node *p){this->son.push_back(p);}
            std::vector<Node*> children(){return this->son;}
            bool get_visited()const {return this->visited;}
            void set_visited(bool visited){this->visited=visited;}
            void set_parent(Node *par){this->parent=par;};
            Node* get_parent(){return this->parent;}
    };

    class OrgChart
    {
        private:

        

        public:
        Node *root;
        std::vector<Node*>All_P;
        std::vector<std::string> Res;
        std::vector<std::string> Res2;

        void BFS(Node *root);
        void DFS(Node *root);
        void Reverse(Node *root);
        OrgChart();
        OrgChart(const OrgChart &org);
        ~OrgChart();
        OrgChart(OrgChart &&)noexcept;
        OrgChart &operator=(const OrgChart &org);
        OrgChart& operator=(OrgChart &&org)noexcept;
        bool operator!=(const Node &root);
        bool operator==(const Node &root);
        OrgChart &add_root(const std::string &root_data);
        OrgChart &add_sub(const std::string &parent, const std::string &child);

        std::string* begin_level_order();
        std::string* end_level_order();

        std::string* begin_reverse_order();
        std::string* reverse_order();

        std::string* begin_preorder();
        std::string* end_preorder();

        std::string* begin();
        std::string* end();
         friend std::ostream& operator<<(std::ostream& out,   OrgChart &Chart);
    };

}