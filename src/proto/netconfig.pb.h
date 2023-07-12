// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: netconfig.proto

#ifndef PROTOBUF_INCLUDED_netconfig_2eproto
#define PROTOBUF_INCLUDED_netconfig_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_netconfig_2eproto 

namespace protobuf_netconfig_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_netconfig_2eproto
class NetConfig;
class NetConfigDefaultTypeInternal;
extern NetConfigDefaultTypeInternal _NetConfig_default_instance_;
namespace google {
namespace protobuf {
template<> ::NetConfig* Arena::CreateMaybeMessage<::NetConfig>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class NetConfig : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetConfig) */ {
 public:
  NetConfig();
  virtual ~NetConfig();

  NetConfig(const NetConfig& from);

  inline NetConfig& operator=(const NetConfig& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  NetConfig(NetConfig&& from) noexcept
    : NetConfig() {
    *this = ::std::move(from);
  }

  inline NetConfig& operator=(NetConfig&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const NetConfig& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NetConfig* internal_default_instance() {
    return reinterpret_cast<const NetConfig*>(
               &_NetConfig_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(NetConfig* other);
  friend void swap(NetConfig& a, NetConfig& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline NetConfig* New() const final {
    return CreateMaybeMessage<NetConfig>(NULL);
  }

  NetConfig* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<NetConfig>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const NetConfig& from);
  void MergeFrom(const NetConfig& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(NetConfig* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string MqttServerURL = 1;
  void clear_mqttserverurl();
  static const int kMqttServerURLFieldNumber = 1;
  const ::std::string& mqttserverurl() const;
  void set_mqttserverurl(const ::std::string& value);
  #if LANG_CXX11
  void set_mqttserverurl(::std::string&& value);
  #endif
  void set_mqttserverurl(const char* value);
  void set_mqttserverurl(const char* value, size_t size);
  ::std::string* mutable_mqttserverurl();
  ::std::string* release_mqttserverurl();
  void set_allocated_mqttserverurl(::std::string* mqttserverurl);

  // string MqttClientName = 2;
  void clear_mqttclientname();
  static const int kMqttClientNameFieldNumber = 2;
  const ::std::string& mqttclientname() const;
  void set_mqttclientname(const ::std::string& value);
  #if LANG_CXX11
  void set_mqttclientname(::std::string&& value);
  #endif
  void set_mqttclientname(const char* value);
  void set_mqttclientname(const char* value, size_t size);
  ::std::string* mutable_mqttclientname();
  ::std::string* release_mqttclientname();
  void set_allocated_mqttclientname(::std::string* mqttclientname);

  // string MqttName = 3;
  void clear_mqttname();
  static const int kMqttNameFieldNumber = 3;
  const ::std::string& mqttname() const;
  void set_mqttname(const ::std::string& value);
  #if LANG_CXX11
  void set_mqttname(::std::string&& value);
  #endif
  void set_mqttname(const char* value);
  void set_mqttname(const char* value, size_t size);
  ::std::string* mutable_mqttname();
  ::std::string* release_mqttname();
  void set_allocated_mqttname(::std::string* mqttname);

  // string MqttPassword = 4;
  void clear_mqttpassword();
  static const int kMqttPasswordFieldNumber = 4;
  const ::std::string& mqttpassword() const;
  void set_mqttpassword(const ::std::string& value);
  #if LANG_CXX11
  void set_mqttpassword(::std::string&& value);
  #endif
  void set_mqttpassword(const char* value);
  void set_mqttpassword(const char* value, size_t size);
  ::std::string* mutable_mqttpassword();
  ::std::string* release_mqttpassword();
  void set_allocated_mqttpassword(::std::string* mqttpassword);

  // string ClientHost = 5;
  void clear_clienthost();
  static const int kClientHostFieldNumber = 5;
  const ::std::string& clienthost() const;
  void set_clienthost(const ::std::string& value);
  #if LANG_CXX11
  void set_clienthost(::std::string&& value);
  #endif
  void set_clienthost(const char* value);
  void set_clienthost(const char* value, size_t size);
  ::std::string* mutable_clienthost();
  ::std::string* release_clienthost();
  void set_allocated_clienthost(::std::string* clienthost);

  // string ServerHost = 7;
  void clear_serverhost();
  static const int kServerHostFieldNumber = 7;
  const ::std::string& serverhost() const;
  void set_serverhost(const ::std::string& value);
  #if LANG_CXX11
  void set_serverhost(::std::string&& value);
  #endif
  void set_serverhost(const char* value);
  void set_serverhost(const char* value, size_t size);
  ::std::string* mutable_serverhost();
  ::std::string* release_serverhost();
  void set_allocated_serverhost(::std::string* serverhost);

  // int32 TCPClientPort = 6;
  void clear_tcpclientport();
  static const int kTCPClientPortFieldNumber = 6;
  ::google::protobuf::int32 tcpclientport() const;
  void set_tcpclientport(::google::protobuf::int32 value);

  // int32 TCPServerPort = 8;
  void clear_tcpserverport();
  static const int kTCPServerPortFieldNumber = 8;
  ::google::protobuf::int32 tcpserverport() const;
  void set_tcpserverport(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:NetConfig)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr mqttserverurl_;
  ::google::protobuf::internal::ArenaStringPtr mqttclientname_;
  ::google::protobuf::internal::ArenaStringPtr mqttname_;
  ::google::protobuf::internal::ArenaStringPtr mqttpassword_;
  ::google::protobuf::internal::ArenaStringPtr clienthost_;
  ::google::protobuf::internal::ArenaStringPtr serverhost_;
  ::google::protobuf::int32 tcpclientport_;
  ::google::protobuf::int32 tcpserverport_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_netconfig_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// NetConfig

// string MqttServerURL = 1;
inline void NetConfig::clear_mqttserverurl() {
  mqttserverurl_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& NetConfig::mqttserverurl() const {
  // @@protoc_insertion_point(field_get:NetConfig.MqttServerURL)
  return mqttserverurl_.GetNoArena();
}
inline void NetConfig::set_mqttserverurl(const ::std::string& value) {
  
  mqttserverurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetConfig.MqttServerURL)
}
#if LANG_CXX11
inline void NetConfig::set_mqttserverurl(::std::string&& value) {
  
  mqttserverurl_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetConfig.MqttServerURL)
}
#endif
inline void NetConfig::set_mqttserverurl(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  mqttserverurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetConfig.MqttServerURL)
}
inline void NetConfig::set_mqttserverurl(const char* value, size_t size) {
  
  mqttserverurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetConfig.MqttServerURL)
}
inline ::std::string* NetConfig::mutable_mqttserverurl() {
  
  // @@protoc_insertion_point(field_mutable:NetConfig.MqttServerURL)
  return mqttserverurl_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* NetConfig::release_mqttserverurl() {
  // @@protoc_insertion_point(field_release:NetConfig.MqttServerURL)
  
  return mqttserverurl_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NetConfig::set_allocated_mqttserverurl(::std::string* mqttserverurl) {
  if (mqttserverurl != NULL) {
    
  } else {
    
  }
  mqttserverurl_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), mqttserverurl);
  // @@protoc_insertion_point(field_set_allocated:NetConfig.MqttServerURL)
}

// string MqttClientName = 2;
inline void NetConfig::clear_mqttclientname() {
  mqttclientname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& NetConfig::mqttclientname() const {
  // @@protoc_insertion_point(field_get:NetConfig.MqttClientName)
  return mqttclientname_.GetNoArena();
}
inline void NetConfig::set_mqttclientname(const ::std::string& value) {
  
  mqttclientname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetConfig.MqttClientName)
}
#if LANG_CXX11
inline void NetConfig::set_mqttclientname(::std::string&& value) {
  
  mqttclientname_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetConfig.MqttClientName)
}
#endif
inline void NetConfig::set_mqttclientname(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  mqttclientname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetConfig.MqttClientName)
}
inline void NetConfig::set_mqttclientname(const char* value, size_t size) {
  
  mqttclientname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetConfig.MqttClientName)
}
inline ::std::string* NetConfig::mutable_mqttclientname() {
  
  // @@protoc_insertion_point(field_mutable:NetConfig.MqttClientName)
  return mqttclientname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* NetConfig::release_mqttclientname() {
  // @@protoc_insertion_point(field_release:NetConfig.MqttClientName)
  
  return mqttclientname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NetConfig::set_allocated_mqttclientname(::std::string* mqttclientname) {
  if (mqttclientname != NULL) {
    
  } else {
    
  }
  mqttclientname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), mqttclientname);
  // @@protoc_insertion_point(field_set_allocated:NetConfig.MqttClientName)
}

// string MqttName = 3;
inline void NetConfig::clear_mqttname() {
  mqttname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& NetConfig::mqttname() const {
  // @@protoc_insertion_point(field_get:NetConfig.MqttName)
  return mqttname_.GetNoArena();
}
inline void NetConfig::set_mqttname(const ::std::string& value) {
  
  mqttname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetConfig.MqttName)
}
#if LANG_CXX11
inline void NetConfig::set_mqttname(::std::string&& value) {
  
  mqttname_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetConfig.MqttName)
}
#endif
inline void NetConfig::set_mqttname(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  mqttname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetConfig.MqttName)
}
inline void NetConfig::set_mqttname(const char* value, size_t size) {
  
  mqttname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetConfig.MqttName)
}
inline ::std::string* NetConfig::mutable_mqttname() {
  
  // @@protoc_insertion_point(field_mutable:NetConfig.MqttName)
  return mqttname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* NetConfig::release_mqttname() {
  // @@protoc_insertion_point(field_release:NetConfig.MqttName)
  
  return mqttname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NetConfig::set_allocated_mqttname(::std::string* mqttname) {
  if (mqttname != NULL) {
    
  } else {
    
  }
  mqttname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), mqttname);
  // @@protoc_insertion_point(field_set_allocated:NetConfig.MqttName)
}

// string MqttPassword = 4;
inline void NetConfig::clear_mqttpassword() {
  mqttpassword_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& NetConfig::mqttpassword() const {
  // @@protoc_insertion_point(field_get:NetConfig.MqttPassword)
  return mqttpassword_.GetNoArena();
}
inline void NetConfig::set_mqttpassword(const ::std::string& value) {
  
  mqttpassword_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetConfig.MqttPassword)
}
#if LANG_CXX11
inline void NetConfig::set_mqttpassword(::std::string&& value) {
  
  mqttpassword_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetConfig.MqttPassword)
}
#endif
inline void NetConfig::set_mqttpassword(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  mqttpassword_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetConfig.MqttPassword)
}
inline void NetConfig::set_mqttpassword(const char* value, size_t size) {
  
  mqttpassword_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetConfig.MqttPassword)
}
inline ::std::string* NetConfig::mutable_mqttpassword() {
  
  // @@protoc_insertion_point(field_mutable:NetConfig.MqttPassword)
  return mqttpassword_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* NetConfig::release_mqttpassword() {
  // @@protoc_insertion_point(field_release:NetConfig.MqttPassword)
  
  return mqttpassword_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NetConfig::set_allocated_mqttpassword(::std::string* mqttpassword) {
  if (mqttpassword != NULL) {
    
  } else {
    
  }
  mqttpassword_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), mqttpassword);
  // @@protoc_insertion_point(field_set_allocated:NetConfig.MqttPassword)
}

// string ClientHost = 5;
inline void NetConfig::clear_clienthost() {
  clienthost_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& NetConfig::clienthost() const {
  // @@protoc_insertion_point(field_get:NetConfig.ClientHost)
  return clienthost_.GetNoArena();
}
inline void NetConfig::set_clienthost(const ::std::string& value) {
  
  clienthost_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetConfig.ClientHost)
}
#if LANG_CXX11
inline void NetConfig::set_clienthost(::std::string&& value) {
  
  clienthost_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetConfig.ClientHost)
}
#endif
inline void NetConfig::set_clienthost(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  clienthost_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetConfig.ClientHost)
}
inline void NetConfig::set_clienthost(const char* value, size_t size) {
  
  clienthost_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetConfig.ClientHost)
}
inline ::std::string* NetConfig::mutable_clienthost() {
  
  // @@protoc_insertion_point(field_mutable:NetConfig.ClientHost)
  return clienthost_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* NetConfig::release_clienthost() {
  // @@protoc_insertion_point(field_release:NetConfig.ClientHost)
  
  return clienthost_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NetConfig::set_allocated_clienthost(::std::string* clienthost) {
  if (clienthost != NULL) {
    
  } else {
    
  }
  clienthost_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), clienthost);
  // @@protoc_insertion_point(field_set_allocated:NetConfig.ClientHost)
}

// int32 TCPClientPort = 6;
inline void NetConfig::clear_tcpclientport() {
  tcpclientport_ = 0;
}
inline ::google::protobuf::int32 NetConfig::tcpclientport() const {
  // @@protoc_insertion_point(field_get:NetConfig.TCPClientPort)
  return tcpclientport_;
}
inline void NetConfig::set_tcpclientport(::google::protobuf::int32 value) {
  
  tcpclientport_ = value;
  // @@protoc_insertion_point(field_set:NetConfig.TCPClientPort)
}

// string ServerHost = 7;
inline void NetConfig::clear_serverhost() {
  serverhost_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& NetConfig::serverhost() const {
  // @@protoc_insertion_point(field_get:NetConfig.ServerHost)
  return serverhost_.GetNoArena();
}
inline void NetConfig::set_serverhost(const ::std::string& value) {
  
  serverhost_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetConfig.ServerHost)
}
#if LANG_CXX11
inline void NetConfig::set_serverhost(::std::string&& value) {
  
  serverhost_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetConfig.ServerHost)
}
#endif
inline void NetConfig::set_serverhost(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  serverhost_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetConfig.ServerHost)
}
inline void NetConfig::set_serverhost(const char* value, size_t size) {
  
  serverhost_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetConfig.ServerHost)
}
inline ::std::string* NetConfig::mutable_serverhost() {
  
  // @@protoc_insertion_point(field_mutable:NetConfig.ServerHost)
  return serverhost_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* NetConfig::release_serverhost() {
  // @@protoc_insertion_point(field_release:NetConfig.ServerHost)
  
  return serverhost_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NetConfig::set_allocated_serverhost(::std::string* serverhost) {
  if (serverhost != NULL) {
    
  } else {
    
  }
  serverhost_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), serverhost);
  // @@protoc_insertion_point(field_set_allocated:NetConfig.ServerHost)
}

// int32 TCPServerPort = 8;
inline void NetConfig::clear_tcpserverport() {
  tcpserverport_ = 0;
}
inline ::google::protobuf::int32 NetConfig::tcpserverport() const {
  // @@protoc_insertion_point(field_get:NetConfig.TCPServerPort)
  return tcpserverport_;
}
inline void NetConfig::set_tcpserverport(::google::protobuf::int32 value) {
  
  tcpserverport_ = value;
  // @@protoc_insertion_point(field_set:NetConfig.TCPServerPort)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_netconfig_2eproto