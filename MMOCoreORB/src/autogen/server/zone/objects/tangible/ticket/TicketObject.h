/*
 *	autogen/server/zone/objects/tangible/ticket/TicketObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef TICKETOBJECT_H_
#define TICKETOBJECT_H_

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
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

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
namespace packets {
namespace scene {

class AttributeListMessage;

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;

#include "engine/lua/Luna.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace ticket {

class TicketObject : public TangibleObject {
public:
	TicketObject();

	void initializeTransientMembers();

	/**
	 * Fills the attribute list message options that are sent to player creature
	 * @pre { }
	 * @post { }
	 * @param msg attribute list message with the attributes
	 * @param object player creature to which the message is sent
	 */
	void fillAttributeList(AttributeListMessage* msg, CreatureObject* object);

	/**
	 * Handles the radial selection sent by the client
	 * @pre { this object is locked, player is locked }
	 * @post { this object is locked, player is locked }
	 * @returns 0 if successfull
	 */
	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void setDeparturePlanet(const String& departureplanet);

	void setDeparturePoint(const String& departurepoint);

	void setArrivalPlanet(const String& arrival);

	void setArrivalPoint(const String& arrival);

	String getDeparturePlanet();

	String getDeparturePoint();

	String getArrivalPlanet();

	String getArrivalPoint();

	bool isTicketObject();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	TicketObject(DummyConstructorParameter* param);

	virtual ~TicketObject();

	friend class TicketObjectHelper;
};

} // namespace ticket
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::ticket;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace ticket {

class TicketObjectImplementation : public TangibleObjectImplementation {
protected:
	String departurePlanet;

	String departurePoint;

	String arrivalPlanet;

	String arrivalPoint;

public:
	TicketObjectImplementation();

	TicketObjectImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	/**
	 * Fills the attribute list message options that are sent to player creature
	 * @pre { }
	 * @post { }
	 * @param msg attribute list message with the attributes
	 * @param object player creature to which the message is sent
	 */
	void fillAttributeList(AttributeListMessage* msg, CreatureObject* object);

	/**
	 * Handles the radial selection sent by the client
	 * @pre { this object is locked, player is locked }
	 * @post { this object is locked, player is locked }
	 * @returns 0 if successfull
	 */
	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void setDeparturePlanet(const String& departureplanet);

	void setDeparturePoint(const String& departurepoint);

	void setArrivalPlanet(const String& arrival);

	void setArrivalPoint(const String& arrival);

	String getDeparturePlanet();

	String getDeparturePoint();

	String getArrivalPlanet();

	String getArrivalPoint();

	bool isTicketObject();

	WeakReference<TicketObject*> _this;

	operator const TicketObject*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~TicketObjectImplementation();

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

	friend class TicketObject;
};

class TicketObjectAdapter : public TangibleObjectAdapter {
public:
	TicketObjectAdapter(TicketObject* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void setDeparturePlanet(const String& departureplanet);

	void setDeparturePoint(const String& departurepoint);

	void setArrivalPlanet(const String& arrival);

	void setArrivalPoint(const String& arrival);

	String getDeparturePlanet();

	String getDeparturePoint();

	String getArrivalPlanet();

	String getArrivalPoint();

	bool isTicketObject();

};

class TicketObjectHelper : public DistributedObjectClassHelper, public Singleton<TicketObjectHelper> {
	static TicketObjectHelper* staticInitializer;

public:
	TicketObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<TicketObjectHelper>;
};

class LuaTicketObject {
public:
	static const char className[];
	static Luna<LuaTicketObject>::RegType Register[];

	LuaTicketObject(lua_State *L);
	virtual ~LuaTicketObject();

	int _setObject(lua_State *L);
	int _getObject(lua_State *L);
	int initializeTransientMembers(lua_State *L);
	int fillAttributeList(lua_State *L);
	int handleObjectMenuSelect(lua_State *L);
	int setDeparturePlanet(lua_State *L);
	int setDeparturePoint(lua_State *L);
	int setArrivalPlanet(lua_State *L);
	int setArrivalPoint(lua_State *L);
	int getDeparturePlanet(lua_State *L);
	int getDeparturePoint(lua_State *L);
	int getArrivalPlanet(lua_State *L);
	int getArrivalPoint(lua_State *L);
	int isTicketObject(lua_State *L);

	Reference<TicketObject*> realObject;
};

} // namespace ticket
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::ticket;

#endif /*TICKETOBJECT_H_*/
