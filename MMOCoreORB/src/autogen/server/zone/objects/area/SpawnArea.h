/*
 *	autogen/server/zone/objects/area/SpawnArea.h generated by engine3 IDL compiler 0.60
 */

#ifndef SPAWNAREA_H_
#define SPAWNAREA_H_

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
namespace managers {
namespace creature {

class LairSpawn;

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

namespace server {
namespace zone {
namespace objects {
namespace area {

class SpawnAreaObserver;

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

#include "server/zone/objects/area/ActiveArea.h"

#include "system/util/SortedVector.h"

#include "system/util/HashTable.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/Observable.h"

#include "system/lang/Time.h"

namespace server {
namespace zone {
namespace objects {
namespace area {

class SpawnArea : public ActiveArea {
public:
	static const int MINSPAWNINTERVAL = 2000;

	SpawnArea();

	Vector3 getRandomPosition(SceneObject* player);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void buildSpawnList(Vector<unsigned int>* groupCRCs);

	Vector<Reference<LairSpawn*> >* getSpawnList();

	void setTier(int n);

	int getTier() const;

	int getTotalWeighting() const;

	void setMaxSpawnLimit(int n);

	void addNoSpawnArea(SpawnArea* area);

	void tryToSpawn(SceneObject* object);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	SpawnArea(DummyConstructorParameter* param);

	virtual ~SpawnArea();

	friend class SpawnAreaHelper;
};

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

namespace server {
namespace zone {
namespace objects {
namespace area {

class SpawnAreaImplementation : public ActiveAreaImplementation {
protected:
	Vector<Reference<LairSpawn*> > possibleSpawns;

	int totalWeighting;

	int totalSpawnCount;

	int maxSpawnLimit;

	HashTable<unsigned int, int> spawnCountByType;

	HashTable<unsigned long long, unsigned int> spawnTypes;

	Time lastSpawn;

	ManagedReference<SpawnAreaObserver* > exitObserver;

	Vector<ManagedWeakReference<SpawnArea*> > noSpawnAreas;

	int tier;

public:
	static const int MINSPAWNINTERVAL = 2000;

	SpawnAreaImplementation();

	SpawnAreaImplementation(DummyConstructorParameter* param);

	Vector3 getRandomPosition(SceneObject* player);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void buildSpawnList(Vector<unsigned int>* groupCRCs);

	Vector<Reference<LairSpawn*> >* getSpawnList();

	void setTier(int n);

	int getTier() const;

	int getTotalWeighting() const;

	void setMaxSpawnLimit(int n);

	void addNoSpawnArea(SpawnArea* area);

	void tryToSpawn(SceneObject* object);

	WeakReference<SpawnArea*> _this;

	operator const SpawnArea*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~SpawnAreaImplementation();

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

	friend class SpawnArea;
};

class SpawnAreaAdapter : public ActiveAreaAdapter {
public:
	SpawnAreaAdapter(SpawnArea* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setTier(int n);

	int getTier() const;

	int getTotalWeighting() const;

	void setMaxSpawnLimit(int n);

	void addNoSpawnArea(SpawnArea* area);

	void tryToSpawn(SceneObject* object);

};

class SpawnAreaHelper : public DistributedObjectClassHelper, public Singleton<SpawnAreaHelper> {
	static SpawnAreaHelper* staticInitializer;

public:
	SpawnAreaHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<SpawnAreaHelper>;
};

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

#endif /*SPAWNAREA_H_*/
