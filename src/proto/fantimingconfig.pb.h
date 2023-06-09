// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: fantimingconfig.proto

#ifndef PROTOBUF_INCLUDED_fantimingconfig_2eproto
#define PROTOBUF_INCLUDED_fantimingconfig_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_fantimingconfig_2eproto 

namespace protobuf_fantimingconfig_2eproto {
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
}  // namespace protobuf_fantimingconfig_2eproto
class FanTimingConfig;
class FanTimingConfigDefaultTypeInternal;
extern FanTimingConfigDefaultTypeInternal _FanTimingConfig_default_instance_;
namespace google {
namespace protobuf {
template<> ::FanTimingConfig* Arena::CreateMaybeMessage<::FanTimingConfig>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class FanTimingConfig : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:FanTimingConfig) */ {
 public:
  FanTimingConfig();
  virtual ~FanTimingConfig();

  FanTimingConfig(const FanTimingConfig& from);

  inline FanTimingConfig& operator=(const FanTimingConfig& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  FanTimingConfig(FanTimingConfig&& from) noexcept
    : FanTimingConfig() {
    *this = ::std::move(from);
  }

  inline FanTimingConfig& operator=(FanTimingConfig&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const FanTimingConfig& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FanTimingConfig* internal_default_instance() {
    return reinterpret_cast<const FanTimingConfig*>(
               &_FanTimingConfig_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(FanTimingConfig* other);
  friend void swap(FanTimingConfig& a, FanTimingConfig& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline FanTimingConfig* New() const final {
    return CreateMaybeMessage<FanTimingConfig>(NULL);
  }

  FanTimingConfig* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<FanTimingConfig>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const FanTimingConfig& from);
  void MergeFrom(const FanTimingConfig& from);
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
  void InternalSwap(FanTimingConfig* other);
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

  // string active = 1;
  void clear_active();
  static const int kActiveFieldNumber = 1;
  const ::std::string& active() const;
  void set_active(const ::std::string& value);
  #if LANG_CXX11
  void set_active(::std::string&& value);
  #endif
  void set_active(const char* value);
  void set_active(const char* value, size_t size);
  ::std::string* mutable_active();
  ::std::string* release_active();
  void set_allocated_active(::std::string* active);

  // string baseTime = 2;
  void clear_basetime();
  static const int kBaseTimeFieldNumber = 2;
  const ::std::string& basetime() const;
  void set_basetime(const ::std::string& value);
  #if LANG_CXX11
  void set_basetime(::std::string&& value);
  #endif
  void set_basetime(const char* value);
  void set_basetime(const char* value, size_t size);
  ::std::string* mutable_basetime();
  ::std::string* release_basetime();
  void set_allocated_basetime(::std::string* basetime);

  // string endTime = 3;
  void clear_endtime();
  static const int kEndTimeFieldNumber = 3;
  const ::std::string& endtime() const;
  void set_endtime(const ::std::string& value);
  #if LANG_CXX11
  void set_endtime(::std::string&& value);
  #endif
  void set_endtime(const char* value);
  void set_endtime(const char* value, size_t size);
  ::std::string* mutable_endtime();
  ::std::string* release_endtime();
  void set_allocated_endtime(::std::string* endtime);

  // int32 interval = 4;
  void clear_interval();
  static const int kIntervalFieldNumber = 4;
  ::google::protobuf::int32 interval() const;
  void set_interval(::google::protobuf::int32 value);

  // int32 openMin = 5;
  void clear_openmin();
  static const int kOpenMinFieldNumber = 5;
  ::google::protobuf::int32 openmin() const;
  void set_openmin(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:FanTimingConfig)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr active_;
  ::google::protobuf::internal::ArenaStringPtr basetime_;
  ::google::protobuf::internal::ArenaStringPtr endtime_;
  ::google::protobuf::int32 interval_;
  ::google::protobuf::int32 openmin_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_fantimingconfig_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FanTimingConfig

// string active = 1;
inline void FanTimingConfig::clear_active() {
  active_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& FanTimingConfig::active() const {
  // @@protoc_insertion_point(field_get:FanTimingConfig.active)
  return active_.GetNoArena();
}
inline void FanTimingConfig::set_active(const ::std::string& value) {
  
  active_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:FanTimingConfig.active)
}
#if LANG_CXX11
inline void FanTimingConfig::set_active(::std::string&& value) {
  
  active_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:FanTimingConfig.active)
}
#endif
inline void FanTimingConfig::set_active(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  active_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:FanTimingConfig.active)
}
inline void FanTimingConfig::set_active(const char* value, size_t size) {
  
  active_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:FanTimingConfig.active)
}
inline ::std::string* FanTimingConfig::mutable_active() {
  
  // @@protoc_insertion_point(field_mutable:FanTimingConfig.active)
  return active_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FanTimingConfig::release_active() {
  // @@protoc_insertion_point(field_release:FanTimingConfig.active)
  
  return active_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FanTimingConfig::set_allocated_active(::std::string* active) {
  if (active != NULL) {
    
  } else {
    
  }
  active_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), active);
  // @@protoc_insertion_point(field_set_allocated:FanTimingConfig.active)
}

// string baseTime = 2;
inline void FanTimingConfig::clear_basetime() {
  basetime_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& FanTimingConfig::basetime() const {
  // @@protoc_insertion_point(field_get:FanTimingConfig.baseTime)
  return basetime_.GetNoArena();
}
inline void FanTimingConfig::set_basetime(const ::std::string& value) {
  
  basetime_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:FanTimingConfig.baseTime)
}
#if LANG_CXX11
inline void FanTimingConfig::set_basetime(::std::string&& value) {
  
  basetime_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:FanTimingConfig.baseTime)
}
#endif
inline void FanTimingConfig::set_basetime(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  basetime_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:FanTimingConfig.baseTime)
}
inline void FanTimingConfig::set_basetime(const char* value, size_t size) {
  
  basetime_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:FanTimingConfig.baseTime)
}
inline ::std::string* FanTimingConfig::mutable_basetime() {
  
  // @@protoc_insertion_point(field_mutable:FanTimingConfig.baseTime)
  return basetime_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FanTimingConfig::release_basetime() {
  // @@protoc_insertion_point(field_release:FanTimingConfig.baseTime)
  
  return basetime_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FanTimingConfig::set_allocated_basetime(::std::string* basetime) {
  if (basetime != NULL) {
    
  } else {
    
  }
  basetime_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), basetime);
  // @@protoc_insertion_point(field_set_allocated:FanTimingConfig.baseTime)
}

// string endTime = 3;
inline void FanTimingConfig::clear_endtime() {
  endtime_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& FanTimingConfig::endtime() const {
  // @@protoc_insertion_point(field_get:FanTimingConfig.endTime)
  return endtime_.GetNoArena();
}
inline void FanTimingConfig::set_endtime(const ::std::string& value) {
  
  endtime_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:FanTimingConfig.endTime)
}
#if LANG_CXX11
inline void FanTimingConfig::set_endtime(::std::string&& value) {
  
  endtime_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:FanTimingConfig.endTime)
}
#endif
inline void FanTimingConfig::set_endtime(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  endtime_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:FanTimingConfig.endTime)
}
inline void FanTimingConfig::set_endtime(const char* value, size_t size) {
  
  endtime_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:FanTimingConfig.endTime)
}
inline ::std::string* FanTimingConfig::mutable_endtime() {
  
  // @@protoc_insertion_point(field_mutable:FanTimingConfig.endTime)
  return endtime_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FanTimingConfig::release_endtime() {
  // @@protoc_insertion_point(field_release:FanTimingConfig.endTime)
  
  return endtime_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FanTimingConfig::set_allocated_endtime(::std::string* endtime) {
  if (endtime != NULL) {
    
  } else {
    
  }
  endtime_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), endtime);
  // @@protoc_insertion_point(field_set_allocated:FanTimingConfig.endTime)
}

// int32 interval = 4;
inline void FanTimingConfig::clear_interval() {
  interval_ = 0;
}
inline ::google::protobuf::int32 FanTimingConfig::interval() const {
  // @@protoc_insertion_point(field_get:FanTimingConfig.interval)
  return interval_;
}
inline void FanTimingConfig::set_interval(::google::protobuf::int32 value) {
  
  interval_ = value;
  // @@protoc_insertion_point(field_set:FanTimingConfig.interval)
}

// int32 openMin = 5;
inline void FanTimingConfig::clear_openmin() {
  openmin_ = 0;
}
inline ::google::protobuf::int32 FanTimingConfig::openmin() const {
  // @@protoc_insertion_point(field_get:FanTimingConfig.openMin)
  return openmin_;
}
inline void FanTimingConfig::set_openmin(::google::protobuf::int32 value) {
  
  openmin_ = value;
  // @@protoc_insertion_point(field_set:FanTimingConfig.openMin)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_fantimingconfig_2eproto
