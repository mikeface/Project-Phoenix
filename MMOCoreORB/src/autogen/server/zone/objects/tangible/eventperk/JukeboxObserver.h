/*
 *	autogen/server/zone/objects/tangible/eventperk/JukeboxObserver.h generated by engine3 IDL compiler 0.60
 */

#ifndef JUKEBOXOBSERVER_H_
#define JUKEBOXOBSERVER_H_

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
namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace eventperk {

class Jukebox;

} // namespace eventperk
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::eventperk;

#include "engine/core/ManagedObject.h"

#include "templates/params/ObserverEventType.h"

#include "engine/log/Logger.h"

#include "engine/core/ManagedReference.h"

#include "engine/util/Facade.h"

#include "system/lang/ref/Reference.h"

#include "engine/core/Task.h"

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class JukeboxObserver : public Observer {
public:
	JukeboxObserver(Jukebox* jbox);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	JukeboxObserver(DummyConstructorParameter* param);

	virtual ~JukeboxObserver();

	friend class JukeboxObserverHelper;
};

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class JukeboxObserverImplementation : public ObserverImplementation {
protected:
	ManagedWeakReference<Jukebox* > jukebox;

public:
	JukeboxObserverImplementation(Jukebox* jbox);

	JukeboxObserverImplementation(DummyConstructorParameter* param);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	WeakReference<JukeboxObserver*> _this;

	operator const JukeboxObserver*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~JukeboxObserverImplementation();

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

	friend class JukeboxObserver;
};

class JukeboxObserverAdapter : public ObserverAdapter {
public:
	JukeboxObserverAdapter(JukeboxObserver* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

};

class JukeboxObserverHelper : public DistributedObjectClassHelper, public Singleton<JukeboxObserverHelper> {
	static JukeboxObserverHelper* staticInitializer;

public:
	JukeboxObserverHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<JukeboxObserverHelper>;
};

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

#endif /*JUKEBOXOBSERVER_H_*/
