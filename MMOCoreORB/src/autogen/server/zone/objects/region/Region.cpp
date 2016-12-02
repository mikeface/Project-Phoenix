/*
 *	autogen/server/zone/objects/region/Region.cpp generated by engine3 IDL compiler 0.60
 */

#include "Region.h"

#include "server/zone/objects/tangible/terminal/Terminal.h"

#include "server/zone/objects/region/CityRegion.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/scene/SceneObject.h"

/*
 *	RegionStub
 */

enum {RPC_SETCITYREGION__CITYREGION_ = 3495245448,RPC_GETCITYREGION__,RPC_NOTIFYLOADFROMDATABASE__,RPC_ENQUEUEENTEREVENT__SCENEOBJECT_,RPC_ENQUEUEEXITEVENT__SCENEOBJECT_,RPC_NOTIFYENTER__SCENEOBJECT_,RPC_NOTIFYEXIT__SCENEOBJECT_,RPC_ISREGION__};

Region::Region() : ActiveArea(DummyConstructorParameter::instance()) {
	RegionImplementation* _implementation = new RegionImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("Region");
}

Region::Region(DummyConstructorParameter* param) : ActiveArea(param) {
	_setClassName("Region");
}

Region::~Region() {
}



void Region::setCityRegion(CityRegion* city) {
	RegionImplementation* _implementation = static_cast<RegionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETCITYREGION__CITYREGION_);
		method.addObjectParameter(city);

		method.executeWithVoidReturn();
	} else {
		_implementation->setCityRegion(city);
	}
}

ManagedWeakReference<CityRegion* > Region::getCityRegion() {
	RegionImplementation* _implementation = static_cast<RegionImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCITYREGION__);

		return static_cast<CityRegion*>(method.executeWithObjectReturn());
	} else {
		return _implementation->getCityRegion();
	}
}

void Region::notifyLoadFromDatabase() {
	RegionImplementation* _implementation = static_cast<RegionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYLOADFROMDATABASE__);

		method.executeWithVoidReturn();
	} else {
		_implementation->notifyLoadFromDatabase();
	}
}

void Region::enqueueEnterEvent(SceneObject* obj) {
	RegionImplementation* _implementation = static_cast<RegionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ENQUEUEENTEREVENT__SCENEOBJECT_);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else {
		_implementation->enqueueEnterEvent(obj);
	}
}

void Region::enqueueExitEvent(SceneObject* obj) {
	RegionImplementation* _implementation = static_cast<RegionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ENQUEUEEXITEVENT__SCENEOBJECT_);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else {
		_implementation->enqueueExitEvent(obj);
	}
}

void Region::notifyEnter(SceneObject* object) {
	RegionImplementation* _implementation = static_cast<RegionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYENTER__SCENEOBJECT_);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else {
		_implementation->notifyEnter(object);
	}
}

void Region::notifyExit(SceneObject* object) {
	RegionImplementation* _implementation = static_cast<RegionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYEXIT__SCENEOBJECT_);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else {
		_implementation->notifyExit(object);
	}
}

bool Region::isRegion() {
	RegionImplementation* _implementation = static_cast<RegionImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISREGION__);

		return method.executeWithBooleanReturn();
	} else {
		return _implementation->isRegion();
	}
}

DistributedObjectServant* Region::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* Region::_getImplementationForRead() const {
	return _impl;
}

void Region::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	RegionImplementation
 */

RegionImplementation::RegionImplementation(DummyConstructorParameter* param) : ActiveAreaImplementation(param) {
	_initializeImplementation();
}


RegionImplementation::~RegionImplementation() {
}


void RegionImplementation::finalize() {
}

void RegionImplementation::_initializeImplementation() {
	_setClassHelper(RegionHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void RegionImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<Region*>(stub);
	ActiveAreaImplementation::_setStub(stub);
}

DistributedObjectStub* RegionImplementation::_getStub() {
	return _this.get();
}

RegionImplementation::operator const Region*() {
	return _this.get();
}

void RegionImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void RegionImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void RegionImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void RegionImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void RegionImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void RegionImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void RegionImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void RegionImplementation::_serializationHelperMethod() {
	ActiveAreaImplementation::_serializationHelperMethod();

	_setClassName("Region");

}

void RegionImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(RegionImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool RegionImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ActiveAreaImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0xdcbf57b1: //Region.cityRegion
		TypeInfo<ManagedWeakReference<CityRegion* > >::parseFromBinaryStream(&cityRegion, stream);
		return true;

	}

	return false;
}

void RegionImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = RegionImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int RegionImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ActiveAreaImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	_nameHashCode = 0xdcbf57b1; //Region.cityRegion
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ManagedWeakReference<CityRegion* > >::toBinaryStream(&cityRegion, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 1;
}

RegionImplementation::RegionImplementation() : ActiveAreaImplementation() {
	_initializeImplementation();
}

void RegionImplementation::setCityRegion(CityRegion* city) {
	// server/zone/objects/region/Region.idl():  		cityRegion = city;
	cityRegion = city;
}

ManagedWeakReference<CityRegion* > RegionImplementation::getCityRegion() {
	// server/zone/objects/region/Region.idl():  		return cityRegion;
	return cityRegion;
}

void RegionImplementation::enqueueEnterEvent(SceneObject* obj) {
	// server/zone/objects/region/Region.idl():  		notifyEnter(obj);
	notifyEnter(obj);
}

void RegionImplementation::enqueueExitEvent(SceneObject* obj) {
	// server/zone/objects/region/Region.idl():  		notifyExit(obj);
	notifyExit(obj);
}

void RegionImplementation::notifyEnter(SceneObject* object) {
	// server/zone/objects/region/Region.idl():  		super.notifyEnter(object);
	ActiveAreaImplementation::notifyEnter(object);
	// server/zone/objects/region/Region.idl():  		CityRegion strongReference = cityRegion;
	ManagedReference<CityRegion* > strongReference = cityRegion;
	// server/zone/objects/region/Region.idl():  		synchronized 
	if (strongReference == NULL)	// server/zone/objects/region/Region.idl():  			return;
	return;
	// server/zone/objects/region/Region.idl():  		}
{
	Locker _locker(strongReference);
	// server/zone/objects/region/Region.idl():  			strongReference.notifyEnter(object);
	strongReference->notifyEnter(object);
}
}

void RegionImplementation::notifyExit(SceneObject* object) {
	// server/zone/objects/region/Region.idl():  		super.notifyExit(object);
	ActiveAreaImplementation::notifyExit(object);
	// server/zone/objects/region/Region.idl():  		CityRegion strongReference = cityRegion;
	ManagedReference<CityRegion* > strongReference = cityRegion;
	// server/zone/objects/region/Region.idl():  		synchronized 
	if (strongReference == NULL)	// server/zone/objects/region/Region.idl():  			return;
	return;
	// server/zone/objects/region/Region.idl():  		}
{
	Locker _locker(strongReference);
	// server/zone/objects/region/Region.idl():  			strongReference.notifyExit(object);
	strongReference->notifyExit(object);
}
}

bool RegionImplementation::isRegion() {
	// server/zone/objects/region/Region.idl():  		return true;
	return true;
}

/*
 *	RegionAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


RegionAdapter::RegionAdapter(Region* obj) : ActiveAreaAdapter(obj) {
}

void RegionAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_SETCITYREGION__CITYREGION_:
		{
			CityRegion* city = static_cast<CityRegion*>(inv->getObjectParameter());
			
			setCityRegion(city);
			
		}
		break;
	case RPC_GETCITYREGION__:
		{
			
			DistributedObject* _m_res = getCityRegion().get();
			resp->insertLong(_m_res == NULL ? 0 : _m_res->_getObjectID());
		}
		break;
	case RPC_NOTIFYLOADFROMDATABASE__:
		{
			
			notifyLoadFromDatabase();
			
		}
		break;
	case RPC_ENQUEUEENTEREVENT__SCENEOBJECT_:
		{
			SceneObject* obj = static_cast<SceneObject*>(inv->getObjectParameter());
			
			enqueueEnterEvent(obj);
			
		}
		break;
	case RPC_ENQUEUEEXITEVENT__SCENEOBJECT_:
		{
			SceneObject* obj = static_cast<SceneObject*>(inv->getObjectParameter());
			
			enqueueExitEvent(obj);
			
		}
		break;
	case RPC_NOTIFYENTER__SCENEOBJECT_:
		{
			SceneObject* object = static_cast<SceneObject*>(inv->getObjectParameter());
			
			notifyEnter(object);
			
		}
		break;
	case RPC_NOTIFYEXIT__SCENEOBJECT_:
		{
			SceneObject* object = static_cast<SceneObject*>(inv->getObjectParameter());
			
			notifyExit(object);
			
		}
		break;
	case RPC_ISREGION__:
		{
			
			bool _m_res = isRegion();
			resp->insertBoolean(_m_res);
		}
		break;
	default:
		ActiveAreaAdapter::invokeMethod(methid, inv);
	}
}

void RegionAdapter::setCityRegion(CityRegion* city) {
	(static_cast<Region*>(stub))->setCityRegion(city);
}

ManagedWeakReference<CityRegion* > RegionAdapter::getCityRegion() {
	return (static_cast<Region*>(stub))->getCityRegion();
}

void RegionAdapter::notifyLoadFromDatabase() {
	(static_cast<Region*>(stub))->notifyLoadFromDatabase();
}

void RegionAdapter::enqueueEnterEvent(SceneObject* obj) {
	(static_cast<Region*>(stub))->enqueueEnterEvent(obj);
}

void RegionAdapter::enqueueExitEvent(SceneObject* obj) {
	(static_cast<Region*>(stub))->enqueueExitEvent(obj);
}

void RegionAdapter::notifyEnter(SceneObject* object) {
	(static_cast<Region*>(stub))->notifyEnter(object);
}

void RegionAdapter::notifyExit(SceneObject* object) {
	(static_cast<Region*>(stub))->notifyExit(object);
}

bool RegionAdapter::isRegion() {
	return (static_cast<Region*>(stub))->isRegion();
}

/*
 *	RegionHelper
 */

RegionHelper* RegionHelper::staticInitializer = RegionHelper::instance();

RegionHelper::RegionHelper() {
	className = "Region";

	Core::getObjectBroker()->registerClass(className, this);
}

void RegionHelper::finalizeHelper() {
	RegionHelper::finalize();
}

DistributedObject* RegionHelper::instantiateObject() {
	return new Region(DummyConstructorParameter::instance());
}

DistributedObjectServant* RegionHelper::instantiateServant() {
	return new RegionImplementation();
}

DistributedObjectAdapter* RegionHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new RegionAdapter(static_cast<Region*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

