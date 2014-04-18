#ifndef PCENTER_H
#define PCENTER_H

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<iostream>
#include<fstream>
#define N 20
extern clock_t start;
extern clock_t endTime;
extern unsigned int stepNum;
extern double disturbValue;
class Vertex{
public:
	Vertex();
	~Vertex();
	double& getx(){ return x; }
	double& gety(){ return y; }
	int& getNwk(int index){ return Nwk[index];}
	double& getEdge_length(int index){ return edge_length[index]; }
	class cmp{
	public:
		cmp(Vertex &v) :vertex(v){}
		Vertex &vertex;
		bool operator()(const int &a, const int &b);
	};
private:
	double x;
	double y;
	std::vector<int> Nwk;
	std::vector<double> edge_length;
};
class Graph{
public:
	Graph(std::string &it);
	~Graph();
	int getNodenumber() { return node_number; }
	Vertex& getNodelist(int index){ return nodelist[index]; };
	void setNwk();
private:
	int node_number;
	Vertex *nodelist;
};
class Facility{
public:
	Facility(int facility_number);
	~Facility();
	int& at(int a, int b, int c){ return *(table + a*node_number * 2 + b*2 + c); }
private:
	int* table;
	const int node_number;
};
class Distance{
public:
	Distance(int facility_number);
	~Distance();
	double& at(int a, int b, int c){ return *(table + a*node_number * 2 + b * 2 + c); }
private:
	double* table;
	const int node_number;
};
class Pcenter{
public:
	Pcenter();
	~Pcenter();
	int getFacilityNumber() const{ return facility_number; }
	double getMaxEdge()const { return max_edge; }
	void initconfig(int facility_number,double max_edge);
	void gentable(int facility_number);
	void setGraph(std::string &it);
	void add_f(int result,int f);
	int initial_f();
	int rand_f(int result);
	double find_max(int result, int *ch);
	int tabu_search(int result);
	void creat_copy(int result);
	void recover(int result);
	void recover_opt(int result);
	int count_obj(int result, double m, int f);
	void delete_f(int result, int f);
	void collective_delete(int result, int f, int r);
	int random_add(int result);
	void save_opt(int result);
	int path_relinking(int first, int last);
	double count_qt(int current, int add, int del);
	void build_x(int m, int n);
	void replace(int m, double opt);
	int count_distance(int k);
	int count_new_distance(int k);
	struct X
	{
		int facility[2000][2];
		double distance[2000][2];
		int population[200];
	}x[200];
	
private:
	int node_number;
	int facility_number;
	double max_edge;
	std::vector< std::vector<int> >  facility_set;
	std::vector< std::vector<int> >  fac_opt;
	std::vector<double> opt_set;
	int *nodeFlag;
	Graph *graph;
	Facility *facility;
	Facility *facility_opt;
	Facility *facility_copy;
	Distance *distance;
	Distance *distance_opt;
	Distance *distance_copy;
	std::vector<unsigned int> add_tabu;
	std::vector<unsigned int> del_tabu;
};

#endif