/*
 *	autogen/server/utils/LambdaObserver.h generated by engine3 IDL compiler 0.60
 */

#ifndef LAMBDAOBSERVER_H_
#define LAMBDAOBSERVER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#ifndef likely
#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#else
#define likely(x)       (x)
#define unlikely(x)     (x)
#endif
#endif
#include "engine/core/ManagedObject.h"

#include "server/utils/LambdaObserverFunction.h"

#include "engine/util/Observable.h"

#include "engine/log/Logger.h"

#include "engine/util/Observer.h"

namespace server {
namespace utils {

class LambdaObserver : public Observer {
public:
	LambdaObserver(LambdaObserverFunction* f);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	LambdaObserver(DummyConstructorParameter* param);

	virtual ~LambdaObserver();

	friend class LambdaObserverHelper;
};

} // namespace utils
} // namespace server

using namespace server::utils;

namespace server {
namespace utils {

class LambdaObserverImplementation : public ObserverImplementation {
	Reference<LambdaObserverFunction* > function;

public:
	LambdaObserverImplementation(LambdaObserverFunction* f);

	LambdaObserverImplementation(DummyConstructorParameter* param);

	virtual int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	WeakReference<LambdaObserver*> _this;

	operator const LambdaObserver*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~LambdaObserverImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class LambdaObserver;
};

class LambdaObserverAdapter : public ObserverAdapter {
public:
	LambdaObserverAdapter(LambdaObserver* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

};

class LambdaObserverHelper : public DistributedObjectClassHelper, public Singleton<LambdaObserverHelper> {
	static LambdaObserverHelper* staticInitializer;

public:
	LambdaObserverHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<LambdaObserverHelper>;
};

} // namespace utils
} // namespace server

using namespace server::utils;

#endif /*LAMBDAOBSERVER_H_*/
