#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

typedef void (base::* TYPE_SIGNAL) (std::string&); // метод передачи сигнала
typedef void (base::* TYPE_HENDLER) (); // метод обработчик
#define signal_d( signal_f ) ( (TYPE_SIGNAL)(&signal_f) // определяю signal_d как метод сигнала
#define handler_d( hendler_f ) (TYPE_HENDLER)(&hendler_f)// определяю hendler_d как метод обработчика int

using namespace std;


/* ДИМА*/
//class base
//{
//private:
//	string name;
//public:
//	vector<base*> children;
//	base* parent;
//	base(string name);
//	base(base* parent = 0);
//	base(base* parent, string name);
//	void setParent(base* parent);
//	
//	string Get_Name();
//	void Set_Name(string name);
//
//	void Set_Status(int status);
//	int Get_Status();
//
//	
//	base* getChild(string name);
//	bool hasChildren();
//	void printTree(string fel = "");
//	int status;
//
//
//
//};
//
//base::base(base* parent) {
//	if (parent != nullptr) {
//		this->parent = parent;
//		parent->children.push_back(this);
//	}
//}
//base::base(string name) {
//	this->name = name;
//}
//base::base(base* parent, string name) {
//	this->name = name;
//	if (parent != nullptr) {
//		this->parent = parent;
//		parent->children.push_back(this);
//	}
//}
//void   base::Set_Name(string name) { this->name = name; }
//string base::Get_Name() { return name; }
//void   base::Set_Status(int status) { this->status = status; }
//int    base::Get_Status() { return status; }
//void base::setParent(base* parent) {
//	this->parent = parent;
//	parent->children.push_back(this);
//}
//bool base::hasChildren() {
//	return children.size() > 0;
//}
//void base::printTree(string fel) {
//	static string s = "";
//	cout << "\n" << s << name;
//	if (this->hasChildren()) {
//		s += "    ";
//		for (int i = 0; i < children.size(); i++) {
//			children[i]->printTree();
//		}
//		if (s.size() > 3) s.resize(s.size() - 4);
//	}
//}
//base* base::getChild(string name) {
//	for (int i = 0; i < children.size(); i++)
//		if (children[i]->Get_Name() == name)
//			return children[i];
//	return 0;
//}
//
//
//
//class der2 : public base {
//public:
//	der2(string name) : base(name) {}
//};
//class der3 : public base {
//public:
//	der3(string name) : base(name) {}
//};
//class der4 : public base {
//public:
//	der4(string name) : base(name) {}
//};
//class der5 : public base {
//public:
//	der5(string name) : base(name) {}
//};
//class der6 : public base {
//public:
//	der6(string name) : base(name) {}
//};
//
//
//
//class application : public base
//{
//private:
//	base* parent;
//	base* child;
//
//public:
//	application() :base() {}
//	void bild_tree_objects();
//	void exec_app();
//	base* get_Parent(string s, base* parent);
//	base* Find_Objects(base* parent, string name);
//	void Find();
//	void Create_ob(int cl, string name, int status);
//	base* Unic(base* root, string name);
//};
//
//void application::Create_ob(int cl, string name, int status) {
//	switch (cl) {
//	case 2: {
//		child = new der2(name);
//		child->status = status;
//		break;
//	}
//	case 3: {
//		child = new der3(name);
//		child->status = status;
//		break;
//	}
//	case 4: {
//		child = new der4(name);
//		child->status = status;
//		break;
//	}
//	case 5: {
//		child = new der5(name);
//		child->status = status;
//		break;
//	}
//	case 6: {
//		child = new der6(name);
//		child->status = status;
//		break;
//	}
//	}
//}
//base* application::Find_Objects(base* parent, string name) {
//	return parent->getChild(name);
//}
//base* application::get_Parent(string s, base* parent) {
//	vector<string> way;
//	string p_name = "";
//	for (int i = 0; i < s.size(); ++i) {
//		if (s[i] == '/') {
//			if (p_name != "")	way.push_back(p_name);
//			p_name = "";
//		}
//		else p_name += s[i];
//	}
//	way.push_back(p_name);
//	if (parent->Get_Name() == way[0]) {
//		for (int i = 1; i < way.size(); ++i) {
//			base* p = parent;
//			if (Find_Objects(p, way[i]) != 0) {
//				parent = Find_Objects(p, way[i]);
//				parent->parent = p;
//			}
//			else return 0;
//		}
//	}
//	else	return 0;
//	return parent;
//}
//void application::Find() {
//	base* parent = this;
//	base* p = parent;
//	base* root = this;
//	string p_name = "";
//	while (p_name != "//") {
//		cin >> p_name;
//		if (p_name != "//") {
//			cout << "\n";
//			if (p_name.substr(0, 2) != "//") {
//				if (get_Parent(p_name, parent) != 0) {
//					parent = get_Parent(p_name, parent);
//					cout << p_name << " Object name: " << parent->Get_Name();
//					parent = p;
//				}
//				else 	cout << p_name << " Object not found";
//			}
//			else {
//				p_name = p_name.substr(2);
//				if (Unic(root, p_name)->Get_Name() == p_name) {
//					parent = Unic(root, p_name);
//					vector<base*> way;
//					base* p_p = parent;
//					while (p_p != root) {
//						way.push_back(p_p);
//						p_p = p_p->parent;
//					}
//					way.push_back(p_p);
//					cout << "//" << p_name << " Object name: " << parent->Get_Name();
//					parent = p;
//				}
//				else cout << "//" << p_name << " Object not found";
//			}
//		}
//	}
//}
//base* application::Unic(base* parent, string name) {
//	base* p = parent;
//	if (parent->Get_Name() != name) {
//		int t = p->children.size();
//		if (p->getChild(name) == 0) {
//			for (int i = 0; i < t; ++i) {
//				p = parent->children[i];
//				p = Unic(p, name);
//				if (p->Get_Name() == name) i = t;
//			}
//		}
//		else {
//			parent = p->getChild(name);
//			return parent;
//		}
//	}
//	return p;
//}
//void application::bild_tree_objects()
//{
//	string name, s = "";
//	cin >> name;
//	this->Set_Name(name);
//	this->Set_Status(1);
//	parent = this;
//	base* p = parent;
//	this->parent = parent;
//	string c_name, p_name = "";
//	int cl, status;
//	while (p_name != "endtree") {
//		cin >> p_name;
//		if (p_name != "endtree") {
//			parent = get_Parent(p_name, parent);
//			cin >> c_name >> cl >> status;
//			Create_ob(cl, c_name, status);
//			child->setParent(parent);
//			parent = p;
//		}
//	}
//}
//
//void application::exec_app()
//{
//	cout << "Object tree";
//	printTree();
//	Find();
//}
//
//
//
//int main()
//{
//	application root;
//
//	root.bild_tree_objects();
//
//	root.exec_app();
//
//	return 0;
//}







class base
{
public:

	base* p_parent;
	string name;
	int o_ready;

public:


	vector<base*>signal_from;
	vector<base*>signal_to;
	vector<int>unique_link_num;

	vector<base*>childhood;

	base() {};
	base(base* _parent);
	base(base* _parent, string nm);
	void set_name(string nm2);
	string get_name();

	base* found_ob(string nm3);

	void test();
	void tree(int level);

	base* get_point(string cord);

	base* create_ob(int num, base* p_par, string nm, int rd_sign);

	void creat_link(int uniq, base* signal_fr, base* signal_t);
	void delete_link(int uniq, base* signal_fr, base* signal_t);
	void deliver_signal(base* signal_fr, string text);

};

base::base(base* _parent, string nm)
{
	/*o_ready = o_sig;*/
	p_parent = _parent;
	name = nm;
}

base::base(base* _parent)
{
	p_parent = _parent;
}

string base::get_name()
{
	return name;
}

base* base::get_point(string cord)
{
	string name_tp = "";

	for (int i = 1; i < cord.length(); i++)
	{

		if (cord[i] != '/')
			name_tp = name_tp + cord[i];

		else
			break;

	}

	string ck = "";

	for (int i = name_tp.length() + 1; i < cord.length(); i++)
	{

		ck = ck + cord[i];

	}

	if (ck == "" && this->name == name_tp)
		return this;

	if (this->childhood.empty())
	{
		return 0;
	}
	else
	{
		name_tp = "";
		for (int i = 1; i < ck.length(); i++)
		{
			if (ck[i] != '/')
				name_tp = name_tp + ck[i];
			else
			{
				break;
			}
		}
		for (int j = 0; j < this->childhood.size(); j++)
		{
			if (this->childhood[j]->name == name_tp)
			{
				base* temp;
				return this->childhood[j]->get_point(ck);
			}
		}

	}
	return 0;
}

void base::set_name(string nm2)
{
	name = nm2;
}

base* base::found_ob(string nm3)
{
	if (this->get_name() == nm3)
		return this;
	if (!childhood.size())
		return 0;

	vector<base*>::iterator it = childhood.begin();
	base* obj;

	while (it != childhood.end())
	{
		obj = (*it)->found_ob(nm3);
		if (!obj)
			it++;
		else
			return obj;
	}
	return 0;
}

void base::test()
{
	cout << "\nThe object " << this->name;
	if (o_ready > 0)
		cout << " is ready";
	else
		cout << " is not ready";
	for (int i = 0; i < childhood.size(); i++)
		if (!childhood.empty())
			childhood[i]->test();
}

void base::tree(int level)
{
	if (childhood.empty())
	{
		cout << "\n";
		level = level + 1;
		for (int i = 0; i < (level * 4); i++)
			cout << " ";
		cout << this->name;
		return;
	}

	if (!childhood.empty())
	{
		cout << "\n";
		level = level + 1;
		for (int i = 0; i < (level * 4); i++)
			cout << " ";
		cout << this->name;
		for (int i = 0; i < childhood.size(); i++)
		{
			childhood[i]->tree(level);
		}
		return;
	}
}

void base::creat_link(int uniq, base* signal_fr, base* signal_t) {
	this->signal_from.push_back(signal_fr);
	this->signal_to.push_back(signal_t);
	this->unique_link_num.push_back(uniq);
}

void base::delete_link(int uniq, base* signal_fr, base* signal_t) {
	for (int i = 0; i < unique_link_num.size(); i++) {
		if (uniq == unique_link_num[i])
		{
			this->unique_link_num.erase(unique_link_num.begin() + i);
			this->signal_to.erase(signal_to.begin() + i);
			this->signal_from.erase(signal_from.begin() + i);
		}
	}
}

void base::deliver_signal(base* signal_fr, string text) {
	for (int i = 0; i < signal_from.size(); i++) {
		if (signal_fr == signal_from[i]) {
			cout << "\n" << "Signal to " << signal_to[i]->get_name() << " Text: " << signal_fr->get_name() << " -> " << text;
		}
	}
}


class application : public base
{
public:
	base* get_point_main();
	vector<base*>parent;
	application(base* par, string nm);
	void in_ob(base* p_par, string nm, int rd_sign);
	base* create_ob(int num, base* p_par, string nm, int rd_sign);
	void test();
	void create_apps(application* root);
	void create_be_cord();
	void bild_tree_objects(application* root);
	void exec_app(application* root);

	void create_link_main(application* root);
	void create_deliver_signal(application* root);
};

class der2 : public base
{
public:
	der2(base* par, string nm);
};
class der3 : public base
{
public:
	der3(base* par, string nm);
};
class der4 : public base
{
public:
	der4(base* par, string nm);
};
class der5 : public base
{
public:
	der5(base* par, string nm);
};
class der6 : public base
{
public:
	der6(base* par, string nm);
};

der2::der2(base* par, string nm) : base(par, nm) {}
der3::der3(base* par, string nm) : base(par, nm) {}
der4::der4(base* par, string nm) : base(par, nm) {}
der5::der5(base* par, string nm) : base(par, nm) {}
der6::der6(base* par, string nm) : base(par, nm) {}



application::application(base* par, string nm) : base(par, nm)
{
}



void application::in_ob(base* p_par, string nm, int rd_sign)
{
	p_parent = p_par;
	name = nm;
	o_ready = rd_sign;
}

base* base::create_ob(int num, base* p_par, string nm, int rd_sign)
{

	switch (num)
	{
	case 2:
		this->o_ready = rd_sign;
		return new der2(p_par, nm);
		break;
	case 3:
		this->o_ready = rd_sign;
		return new der3(p_par, nm);
		break;
	case 4:
		this->o_ready = rd_sign;
		return new der4(p_par, nm);
		break;
	case 5:
		this->o_ready = rd_sign;
		return new der5(p_par, nm);
		break;
	case 6:
		this->o_ready = rd_sign;
		return new der6(p_par, nm);
		break;
	}
}

//void application::tree(int level)
//{
//	if (childhood.empty())
//	{
//		cout << "\n";
//		level = level + 1;
//		for (int i = 0; i < (level * 4); i++)
//			cout << " ";
//		cout << name;
//		return;
//	}
//
//	if (!childhood.empty())
//	{
//		cout << "\n";
//		level = level + 1;
//		for (int i = 0; i < (level * 4); i++)
//			cout << " ";
//		cout << name;
//		for (int i = 0; i < childhood.size(); i++)
//		{
//			childhood[i]->tree(level);
//		}
//		return;
//	}
//}

void application::test()
{
	cout << "\nThe object " << this->name;
	if (o_ready > 0)
		cout << " is ready";
	else
		cout << " is not ready";
	for (int i = 0; i < childhood.size(); i++)
		if (!childhood.empty())
			childhood[i]->test();
}




base* application::get_point_main()
{
	string coordinate = "";
	while (coordinate != "//")

	{
		cin >> coordinate;

		if (coordinate == "//")
			return 0;

		else if (coordinate[1] == '/')//при уникальном имени
		{
			string new_coord = "";

			for (int i = 2; i < coordinate.size(); i++)
			{

				new_coord = new_coord + coordinate[i];

			}

			base* temp_obj;
			temp_obj = this->found_ob(new_coord);//когда надо будет вернуть , я верну 

			if (!temp_obj)
			{
				cout << "\n";
				cout << coordinate << " Object not found";
			}
			else
			{
				cout << "\n";
				cout << coordinate << " Object name: " << temp_obj->name;
			}
		}
		else if (coordinate[1] != '/')
		{

			base* temp_obj2;
			temp_obj2 = this->get_point(coordinate);

			if (!temp_obj2)
			{
				cout << "\n";
				cout << coordinate << " Object not found";
			}
			else
			{
				cout << "\n";
				cout << coordinate << " Object name: " << temp_obj2->name;
			}
		}
	}
}

void application::create_apps(application* root)
{
	string nama;
	cin >> nama;
	root->set_name(nama);
	root->parent.push_back(root);
	string name_par, name_ch;
	name_par = nama;
	int clas_num, sig_r;
	base* child;

	while (name_par != "endtree")
	{
		cin >> name_par;
		if (name_par != "endtree")
		{
			cin >> name_ch >> clas_num >> sig_r;
			for (int i = 0; i < root->parent.size(); i++)
			{
				if (root->parent[i]->get_name() == name_par)
				{
					child = root->parent[i]->create_ob(clas_num, root->parent[i], name_ch, sig_r);
					root->parent.push_back(child);
					root->parent[i]->childhood.push_back(child);

				}
			}
		}
	}
}

//void application::create_be_cord()
//{
//	string coord, name_ch;
//	int class_num, r_signal;
//	base* child1;
//	base* paren;
//	cin >> coord;
//	name = coord;
//
//	while (coord != "endtree")
//	{
//		cin >> coord;
//		if (coord != "endtree")
//		{
//			cin >> name_ch >> class_num >> r_signal;
//			paren = this->get_point(coord);
//			child1 = this->create_ob(class_num, paren, name_ch, r_signal);
//			parent.push_back(child1);
//			paren->childhood.push_back(child1);
//		}
//	}
//}

void application::bild_tree_objects(application*root)
{
	create_apps(root);

}

void application::exec_app(application* root)
{
	cout << "Object tree";
	this->tree(-1);

	create_link_main(root);
	create_deliver_signal(root);


	/*et_point_main();*/ // из лабы 3
}


//лаба 3-4
void application::create_link_main(application* root) {
	int uniq_n;
	base* obj_to;
	base* obj_fr;
	string name_obj_fr, name_obj_to;
	cout << "\nSet connects\n";

	cin >> uniq_n;

	while (uniq_n) {
		cin >> name_obj_fr >> name_obj_to;
		obj_fr = found_ob(name_obj_fr);
		obj_to = found_ob(name_obj_to);
		this->creat_link(uniq_n, obj_fr, obj_to);
		cout << uniq_n << " " << name_obj_fr << " " << name_obj_to << "\n";
		cin >> uniq_n;
	}
}

void application::create_deliver_signal(application* root) {
	cout << "Emit signals";
	base* object_fr;
	string obj_name_fr, signal;
	cin >> obj_name_fr;
	while (obj_name_fr != "endsignals") {
		cin >> signal;
		object_fr = found_ob(obj_name_fr);
		root->deliver_signal(object_fr, signal);
		cin >> obj_name_fr;
	}
}






int main()
{
	application* root = new application(0, "root");
	root->bild_tree_objects(root);
	root->exec_app(root);
}