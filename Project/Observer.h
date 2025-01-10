class IObserver {
public:
	virtual ~IObserver() {};
	virtual void Update() = 0;
};

class ISubject {
public:
	virtual ~ISubject() {};
	virtual void Attach(IObserver* Observer) = 0;
	virtual void Detach(IObserver* Observer) = 0;
	virtual void Notify() = 0;
};