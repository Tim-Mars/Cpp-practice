#include <iostream>
#include <array>
#include <vector>

class Instrument{
	protected:
		std::string m_make{};
		std::string m_model{};
		std::string m_type{};
		Instrument (const Instrument&)=default;
		Instrument& operator=(const Instrument& )= default;
		
	public:
		Instrument(std::string make="Acme", std::string model="Acme 1000",std::string type=" All-o-phone")
				:m_make{make},m_model{model},m_type{type}
				{
					//std::cout<<"Base Constructor Instrument"<<'\n';
				}
		
		void setMake(std::string make)	{m_make = make;}
		void setModel(std::string model){m_make = model;}
		void setType(std::string type)	{m_type = type;}
		std::string getMake()			{return m_make;}
		std::string getModel()			{return m_model;}
		std::string getType()			{return m_type;}
	friend std::ostream& operator<<(std::ostream& out, const Instrument& i){
		out<<" I Make: "<<i.m_make<<'\t'<<" I Model: "<<i.m_model<<'\t'<<" I Type: "<<i.m_type<<'\n';
		return out;
	}
};

class Drum : public Instrument{
	private:
		std::string m_dType{};
		int m_snareSize{};
	public:
		Drum(std::string make = "Acme", std::string model = "A 3000",std::string type = "Drum",
				 std::string dType="Acoustic", int snareSize=16)
			:Instrument{make,model,type} , m_dType{dType}, m_snareSize{snareSize}
			{
				//std::cout<<"Derived Constructor Drum"<<'\n';
			}
		
		void setDType(std::string type)		{m_dType = type;}
		void setSnareSize(int snareSize)	{m_snareSize = snareSize;}
		std::string getDType()				{return m_dType;}
		int getSnareSize()					{return m_snareSize;}
		std::string getMake()			{return m_make;}

		friend std::ostream& operator<<(std::ostream& out, Drum& d){
			out<<"Drum type: "<<d.m_dType<<'\t'<<"Snare: "<<d.m_snareSize<<'\n';
			return out;
		}
};
class Guitar : public Instrument{
	private:
		std::string m_gType{};
		int m_strSize{};
	public:
		Guitar(std::string make = "Acme", std::string model = "A 3000",std::string type = "Guitar",
				 std::string gType="Acoustic", int strSize=32)
			:Instrument{make,model,type} , m_gType{gType}, m_strSize{strSize}
			{
				//std::cout<<"Derived Constructor Guitar"<<'\n';
			}
		
		void setgType(std::string type)		{m_gType = type;}
		void setStrSize(int strSize)		{m_strSize = strSize;}
		std::string getDType()				{return m_gType;}
		int getStrSize()					{return m_strSize;}
		std::string getMake()				{return m_make;}

		friend std::ostream& operator<<(std::ostream& out, Guitar& g){
			out<<"Guitar type: "<<g.m_gType<<'\t'<<"Sting Length: "<<g.m_strSize<<'\n';
			return out;
		}
	
};

int main(){

		
		Drum d1{"Roland"};
		Drum d2{"Ludwig"};
		Drum d3{"Ziadang"};
		Guitar g1{"Fender"};
		Guitar g2{"Rhodes"};
		Guitar g3{};

		//std::vector<Instrument*>insts{&d1,&d2,&d3,&g1,&g2,&g3};
		std::array<Instrument*,6>insts{&d1,&d2,&d3,&g1,&g2,&g3};
		for(auto idx: insts){
			std::cout<<idx->getMake()<<'\n';
		}
		//std::array<Drum,2>d{{{"drummy1"},{"Ludwig"}}};
		//for(const auto& ind: d)
		//	std::cout<<ind<<'\n';
		

		//std::cout<<d<<'\n';
/*
		Drum d{"Roland","DXL3000","Drum","Electronic",14};
		
		Instrument& i2{d};
		std::cout<<"\t\t"<<i2<<'\n';
		Instrument* pi{&d};
		std::cout<<"\t\t"<<pi->getMake()<<'\n';
		std::cout<<"\t\t"<<pi->getType()<<'\n';
*/
    return 0;
}
/*std::cout<<d<<'\n';
		Drum& d2{d};
		std::cout<<d2<<'\n';
		Drum* pd{&d2};
		std::cout<<"\t\t\t\t"<<pd->getSnareSize()<<'\n';
*/