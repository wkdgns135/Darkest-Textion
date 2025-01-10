class Singleton {
private:
	Singleton(){}
	Singleton(const Singleton& Ref){}
	Singleton& operator=(const Singleton& Ref) {};
	~Singleton(){}
public :
	static Singleton& GetInstace() {
		static Singleton Instance;
		return Instance;
	}
};