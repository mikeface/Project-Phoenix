/*
 *	autogen/server/zone/managers/guild/GuildManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef GUILDMANAGER_H_
#define GUILDMANAGER_H_

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

class ZoneProcessServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace chat {

class ChatManager;

} // namespace chat
} // namespace server

using namespace server::chat;

namespace server {
namespace chat {
namespace room {

class ChatRoom;

} // namespace room
} // namespace chat
} // namespace server

using namespace server::chat::room;

namespace server {
namespace zone {
namespace objects {
namespace guild {

class GuildObject;

} // namespace guild
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::guild;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace guild {

class GuildTerminal;

} // namespace guild
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::guild;

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

#include "server/zone/managers/guild/GuildList.h"

#include "server/zone/packets/guild/GuildObjectDeltaMessage3.h"

#include "server/zone/objects/scene/variables/DeltaSet.h"

#include "server/chat/StringIdChatParameter.h"

#include "engine/core/ManagedService.h"

#include "system/lang/StringBuffer.h"

namespace server {
namespace zone {
namespace managers {
namespace guild {

class GuildManager : public ManagedService {
public:
	GuildManager(ZoneServer* serv, ZoneProcessServer* proc);

	void setChatManager(ChatManager* chatmanager);

	void loadLuaConfig();

	void stop();

	void processGuildUpdate(GuildObject* guild);

	void sendGuildListTo(CreatureObject* player, const String& guildFilter);

	void sendAdminGuildInfoTo(CreatureObject* player, GuildObject* guild);

	void addPendingGuild(unsigned long long playerID, const String& guildName);

	void removePendingGuild(unsigned long long playerID);

	String getPendingGuildName(unsigned long long playerID);

	void addSponsoredPlayer(unsigned long long playerID, GuildObject* guild);

	void removeSponsoredPlayer(unsigned long long playerID);

	bool isCreatingGuild(unsigned long long playerID);

	bool isSponsoredPlayer(unsigned long long playerID);

	GuildObject* getSponsoredGuild(unsigned long long playerID);

	void sendBaselinesTo(CreatureObject* player);

	void loadGuilds();

	void sendGuildCreateNameTo(CreatureObject* player, GuildTerminal* guildTerminal);

	void sendGuildChangeNameTo(CreatureObject* player, GuildObject* guild);

	void sendGuildCreateAbbrevTo(CreatureObject* player, GuildTerminal* guildTerminal);

	void sendGuildChangeAbbrevTo(CreatureObject* player, GuildObject* guild);

	void sendGuildInformationTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildMemberListTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildMemberOptionsTo(CreatureObject* player, GuildObject* guild, unsigned long long memberID, GuildTerminal* guildTerminal);

	void sendGuildDisbandConfirmTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildSponsoredListTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildSponsoredOptionsTo(CreatureObject* player, GuildObject* guild, unsigned long long playerID, GuildTerminal* guildTerminal);

	void sendGuildSponsorTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildKickPromptTo(CreatureObject* player, CreatureObject* target);

	void sendGuildSetTitleTo(CreatureObject* player, CreatureObject* target);

	void sendGuildWarStatusTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void promptAddNewEnemy(CreatureObject* player, GuildObject* guild, SceneObject* terminal);

	void toggleWarStatus(CreatureObject* player, GuildObject* guild, unsigned long long guildoid);

	void declareWarByName(CreatureObject* player, GuildObject* guild, const String& search);

	void updateWarStatusToWaringGuild(GuildObject* guild, GuildObject* waringGuild);

	void sendMemberPermissionsTo(CreatureObject* player, unsigned long long targetID, GuildTerminal* guildTerminal);

	bool validateGuildName(CreatureObject* player, const String& guildName, GuildObject* guild = NULL);

	bool validateGuildAbbrev(CreatureObject* player, const String& guildAbbrev, GuildObject* guild = NULL);

	bool guildNameExists(const String& guildName);

	bool guildAbbrevExists(const String& guildAbbrev);

	void setupGuildRename(CreatureObject* player, GuildObject* guild);

	void renameGuild(GuildObject* guild);

	GuildObject* createGuild(CreatureObject* player, const String& guildName, const String& guildAbbrev);

	bool disbandGuild(CreatureObject* player, GuildObject* guild);

	void sponsorPlayer(CreatureObject* player, const String& playerName);

	void acceptSponsorshipRequest(CreatureObject* player, CreatureObject* target);

	void acceptSponsoredPlayer(CreatureObject* player, unsigned long long targetID);

	void declineSponsoredPlayer(CreatureObject* player, unsigned long long targetID);

	void kickMember(CreatureObject* player, CreatureObject* target);

	void leaveGuild(CreatureObject* player, GuildObject* guild);

	void setMemberTitle(CreatureObject* player, CreatureObject* target, const String& title);

	void toggleGuildPermission(CreatureObject* player, unsigned long long targetID, int permissionIndex, GuildTerminal* guildTerminal);

	ChatRoom* createGuildChannels(GuildObject* guild);

	void sendGuildTransferTo(CreatureObject* player, GuildTerminal* guildTerminal);

	void sendTransferAckTo(CreatureObject* player, const String& newOwnerName, SceneObject* guildTerminal);

	void transferLeadership(CreatureObject* newOwner, CreatureObject* oldOwner, bool election);

	void sendAcceptLotsTo(CreatureObject* newOwner, GuildTerminal* guildTerminal);

	bool transferGuildHall(CreatureObject* newOwner, SceneObject* guildTerminal);

	void sendGuildMail(const String& subject, StringIdChatParameter& body, GuildObject* guild);

	GuildObject* getGuildFromAbbrev(const String& guildAbbrev);

	void toggleElection(GuildObject* guild, CreatureObject* player);

	void resetElection(GuildObject* guild, CreatureObject* player);

	void registerForElection(GuildObject* guild, CreatureObject* player);

	void unregisterFromElection(GuildObject* guild, CreatureObject* player);

	void promptCastVote(GuildObject* guild, CreatureObject* player, GuildTerminal* terminal);

	void castVote(GuildObject* guild, CreatureObject* player, unsigned long long candidateID);

	void viewElectionStandings(GuildObject* guild, CreatureObject* player, GuildTerminal* terminal);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	GuildManager(DummyConstructorParameter* param);

	virtual ~GuildManager();

	friend class GuildManagerHelper;
};

} // namespace guild
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::guild;

namespace server {
namespace zone {
namespace managers {
namespace guild {

class GuildManagerImplementation : public ManagedServiceImplementation, public Logger {
	ManagedReference<ZoneServer* > server;

	ManagedReference<ZoneProcessServer* > processor;

	ManagedReference<ChatManager* > chatManager;

	DeltaSet<String, ManagedReference<GuildObject* > > guildList;

	VectorMap<unsigned long long, String> pendingGuilds;

	VectorMap<unsigned long long, ManagedReference<GuildObject* > > sponsoredPlayers;

	int requiredMembers;

	int maximumMembers;

	int guildUpdateInterval;

public:
	GuildManagerImplementation(ZoneServer* serv, ZoneProcessServer* proc);

	GuildManagerImplementation(DummyConstructorParameter* param);

	void setChatManager(ChatManager* chatmanager);

	void loadLuaConfig();

	void stop();

private:
	void scheduleGuildUpdates();

public:
	void processGuildUpdate(GuildObject* guild);

private:
	void processGuildElection(GuildObject* guild);

	void destroyGuild(GuildObject* guild, StringIdChatParameter& mailbody);

public:
	void sendGuildListTo(CreatureObject* player, const String& guildFilter);

	void sendAdminGuildInfoTo(CreatureObject* player, GuildObject* guild);

private:
	void addPermsToAdminGuildInfo(byte perms, StringBuffer& text);

public:
	void addPendingGuild(unsigned long long playerID, const String& guildName);

	void removePendingGuild(unsigned long long playerID);

	String getPendingGuildName(unsigned long long playerID);

	void addSponsoredPlayer(unsigned long long playerID, GuildObject* guild);

	void removeSponsoredPlayer(unsigned long long playerID);

	bool isCreatingGuild(unsigned long long playerID);

	bool isSponsoredPlayer(unsigned long long playerID);

	GuildObject* getSponsoredGuild(unsigned long long playerID);

	void sendBaselinesTo(CreatureObject* player);

	void loadGuilds();

	void sendGuildCreateNameTo(CreatureObject* player, GuildTerminal* guildTerminal);

	void sendGuildChangeNameTo(CreatureObject* player, GuildObject* guild);

	void sendGuildCreateAbbrevTo(CreatureObject* player, GuildTerminal* guildTerminal);

	void sendGuildChangeAbbrevTo(CreatureObject* player, GuildObject* guild);

	void sendGuildInformationTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildMemberListTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildMemberOptionsTo(CreatureObject* player, GuildObject* guild, unsigned long long memberID, GuildTerminal* guildTerminal);

	void sendGuildDisbandConfirmTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildSponsoredListTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildSponsoredOptionsTo(CreatureObject* player, GuildObject* guild, unsigned long long playerID, GuildTerminal* guildTerminal);

	void sendGuildSponsorTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildKickPromptTo(CreatureObject* player, CreatureObject* target);

	void sendGuildSetTitleTo(CreatureObject* player, CreatureObject* target);

	void sendGuildWarStatusTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void promptAddNewEnemy(CreatureObject* player, GuildObject* guild, SceneObject* terminal);

	void toggleWarStatus(CreatureObject* player, GuildObject* guild, unsigned long long guildoid);

	void declareWarByName(CreatureObject* player, GuildObject* guild, const String& search);

	void updateWarStatusToWaringGuild(GuildObject* guild, GuildObject* waringGuild);

	void sendMemberPermissionsTo(CreatureObject* player, unsigned long long targetID, GuildTerminal* guildTerminal);

	bool validateGuildName(CreatureObject* player, const String& guildName, GuildObject* guild = NULL);

	bool validateGuildAbbrev(CreatureObject* player, const String& guildAbbrev, GuildObject* guild = NULL);

	bool guildNameExists(const String& guildName);

	bool guildAbbrevExists(const String& guildAbbrev);

	void setupGuildRename(CreatureObject* player, GuildObject* guild);

	void renameGuild(GuildObject* guild);

	GuildObject* createGuild(CreatureObject* player, const String& guildName, const String& guildAbbrev);

	bool disbandGuild(CreatureObject* player, GuildObject* guild);

	void sponsorPlayer(CreatureObject* player, const String& playerName);

	void acceptSponsorshipRequest(CreatureObject* player, CreatureObject* target);

	void acceptSponsoredPlayer(CreatureObject* player, unsigned long long targetID);

	void declineSponsoredPlayer(CreatureObject* player, unsigned long long targetID);

	void kickMember(CreatureObject* player, CreatureObject* target);

	void leaveGuild(CreatureObject* player, GuildObject* guild);

	void setMemberTitle(CreatureObject* player, CreatureObject* target, const String& title);

	void toggleGuildPermission(CreatureObject* player, unsigned long long targetID, int permissionIndex, GuildTerminal* guildTerminal);

	ChatRoom* createGuildChannels(GuildObject* guild);

	void sendGuildTransferTo(CreatureObject* player, GuildTerminal* guildTerminal);

	void sendTransferAckTo(CreatureObject* player, const String& newOwnerName, SceneObject* guildTerminal);

	void transferLeadership(CreatureObject* newOwner, CreatureObject* oldOwner, bool election);

	void sendAcceptLotsTo(CreatureObject* newOwner, GuildTerminal* guildTerminal);

	bool transferGuildHall(CreatureObject* newOwner, SceneObject* guildTerminal);

	void sendGuildMail(const String& subject, StringIdChatParameter& body, GuildObject* guild);

	GuildObject* getGuildFromAbbrev(const String& guildAbbrev);

	void toggleElection(GuildObject* guild, CreatureObject* player);

	void resetElection(GuildObject* guild, CreatureObject* player);

	void registerForElection(GuildObject* guild, CreatureObject* player);

	void unregisterFromElection(GuildObject* guild, CreatureObject* player);

	void promptCastVote(GuildObject* guild, CreatureObject* player, GuildTerminal* terminal);

	void castVote(GuildObject* guild, CreatureObject* player, unsigned long long candidateID);

	void viewElectionStandings(GuildObject* guild, CreatureObject* player, GuildTerminal* terminal);

	WeakReference<GuildManager*> _this;

	operator const GuildManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~GuildManagerImplementation();

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

	friend class GuildManager;
};

class GuildManagerAdapter : public ManagedServiceAdapter {
public:
	GuildManagerAdapter(GuildManager* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setChatManager(ChatManager* chatmanager);

	void loadLuaConfig();

	void stop();

	void processGuildUpdate(GuildObject* guild);

	void sendGuildListTo(CreatureObject* player, const String& guildFilter);

	void sendAdminGuildInfoTo(CreatureObject* player, GuildObject* guild);

	void addPendingGuild(unsigned long long playerID, const String& guildName);

	void removePendingGuild(unsigned long long playerID);

	String getPendingGuildName(unsigned long long playerID);

	void addSponsoredPlayer(unsigned long long playerID, GuildObject* guild);

	void removeSponsoredPlayer(unsigned long long playerID);

	bool isCreatingGuild(unsigned long long playerID);

	bool isSponsoredPlayer(unsigned long long playerID);

	GuildObject* getSponsoredGuild(unsigned long long playerID);

	void sendBaselinesTo(CreatureObject* player);

	void loadGuilds();

	void sendGuildCreateNameTo(CreatureObject* player, GuildTerminal* guildTerminal);

	void sendGuildChangeNameTo(CreatureObject* player, GuildObject* guild);

	void sendGuildCreateAbbrevTo(CreatureObject* player, GuildTerminal* guildTerminal);

	void sendGuildChangeAbbrevTo(CreatureObject* player, GuildObject* guild);

	void sendGuildInformationTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildMemberListTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildMemberOptionsTo(CreatureObject* player, GuildObject* guild, unsigned long long memberID, GuildTerminal* guildTerminal);

	void sendGuildDisbandConfirmTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildSponsoredListTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildSponsoredOptionsTo(CreatureObject* player, GuildObject* guild, unsigned long long playerID, GuildTerminal* guildTerminal);

	void sendGuildSponsorTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void sendGuildKickPromptTo(CreatureObject* player, CreatureObject* target);

	void sendGuildSetTitleTo(CreatureObject* player, CreatureObject* target);

	void sendGuildWarStatusTo(CreatureObject* player, GuildObject* guild, GuildTerminal* guildTerminal);

	void promptAddNewEnemy(CreatureObject* player, GuildObject* guild, SceneObject* terminal);

	void toggleWarStatus(CreatureObject* player, GuildObject* guild, unsigned long long guildoid);

	void declareWarByName(CreatureObject* player, GuildObject* guild, const String& search);

	void updateWarStatusToWaringGuild(GuildObject* guild, GuildObject* waringGuild);

	void sendMemberPermissionsTo(CreatureObject* player, unsigned long long targetID, GuildTerminal* guildTerminal);

	bool validateGuildName(CreatureObject* player, const String& guildName, GuildObject* guild);

	bool validateGuildAbbrev(CreatureObject* player, const String& guildAbbrev, GuildObject* guild);

	bool guildNameExists(const String& guildName);

	bool guildAbbrevExists(const String& guildAbbrev);

	void setupGuildRename(CreatureObject* player, GuildObject* guild);

	void renameGuild(GuildObject* guild);

	GuildObject* createGuild(CreatureObject* player, const String& guildName, const String& guildAbbrev);

	bool disbandGuild(CreatureObject* player, GuildObject* guild);

	void sponsorPlayer(CreatureObject* player, const String& playerName);

	void acceptSponsorshipRequest(CreatureObject* player, CreatureObject* target);

	void acceptSponsoredPlayer(CreatureObject* player, unsigned long long targetID);

	void declineSponsoredPlayer(CreatureObject* player, unsigned long long targetID);

	void kickMember(CreatureObject* player, CreatureObject* target);

	void leaveGuild(CreatureObject* player, GuildObject* guild);

	void setMemberTitle(CreatureObject* player, CreatureObject* target, const String& title);

	void toggleGuildPermission(CreatureObject* player, unsigned long long targetID, int permissionIndex, GuildTerminal* guildTerminal);

	ChatRoom* createGuildChannels(GuildObject* guild);

	void sendGuildTransferTo(CreatureObject* player, GuildTerminal* guildTerminal);

	void sendTransferAckTo(CreatureObject* player, const String& newOwnerName, SceneObject* guildTerminal);

	void transferLeadership(CreatureObject* newOwner, CreatureObject* oldOwner, bool election);

	void sendAcceptLotsTo(CreatureObject* newOwner, GuildTerminal* guildTerminal);

	bool transferGuildHall(CreatureObject* newOwner, SceneObject* guildTerminal);

	GuildObject* getGuildFromAbbrev(const String& guildAbbrev);

	void toggleElection(GuildObject* guild, CreatureObject* player);

	void resetElection(GuildObject* guild, CreatureObject* player);

	void registerForElection(GuildObject* guild, CreatureObject* player);

	void unregisterFromElection(GuildObject* guild, CreatureObject* player);

	void promptCastVote(GuildObject* guild, CreatureObject* player, GuildTerminal* terminal);

	void castVote(GuildObject* guild, CreatureObject* player, unsigned long long candidateID);

	void viewElectionStandings(GuildObject* guild, CreatureObject* player, GuildTerminal* terminal);

};

class GuildManagerHelper : public DistributedObjectClassHelper, public Singleton<GuildManagerHelper> {
	static GuildManagerHelper* staticInitializer;

public:
	GuildManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<GuildManagerHelper>;
};

} // namespace guild
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::guild;

#endif /*GUILDMANAGER_H_*/
