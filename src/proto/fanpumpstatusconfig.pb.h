// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: fanpumpstatusconfig.proto

#ifndef PROTOBUF_INCLUDED_fanpumpstatusconfig_2eproto
#define PROTOBUF_INCLUDED_fanpumpstatusconfig_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_fanpumpstatusconfig_2eproto 

namespace protobuf_fanpumpstatusconfig_2eproto {
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
}  // namespace protobuf_fanpumpstatusconfig_2eproto
class FanPumpStatusConfig;
class FanPumpStatusConfigDefaultTypeInternal;
extern FanPumpStatusConfigDefaultTypeInternal _FanPumpStatusConfig_default_instance_;
namespace google {
namespace protobuf {
template<> ::FanPumpStatusConfig* Arena::CreateMaybeMessage<::FanPumpStatusConfig>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class FanPumpStatusConfig : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:FanPumpStatusConfig) */ {
 public:
  FanPumpStatusConfig();
  virtual ~FanPumpStatusConfig();

  FanPumpStatusConfig(const FanPumpStatusConfig& from);

  inline FanPumpStatusConfig& operator=(const FanPumpStatusConfig& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  FanPumpStatusConfig(FanPumpStatusConfig&& from) noexcept
    : FanPumpStatusConfig() {
    *this = ::std::move(from);
  }

  inline FanPumpStatusConfig& operator=(FanPumpStatusConfig&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const FanPumpStatusConfig& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FanPumpStatusConfig* internal_default_instance() {
    return reinterpret_cast<const FanPumpStatusConfig*>(
               &_FanPumpStatusConfig_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(FanPumpStatusConfig* other);
  friend void swap(FanPumpStatusConfig& a, FanPumpStatusConfig& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline FanPumpStatusConfig* New() const final {
    return CreateMaybeMessage<FanPumpStatusConfig>(NULL);
  }

  FanPumpStatusConfig* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<FanPumpStatusConfig>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const FanPumpStatusConfig& from);
  void MergeFrom(const FanPumpStatusConfig& from);
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
  void InternalSwap(FanPumpStatusConfig* other);
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

  // string Status = 1;
  void clear_status();
  static const int kStatusFieldNumber = 1;
  const ::std::string& status() const;
  void set_status(const ::std::string& value);
  #if LANG_CXX11
  void set_status(::std::string&& value);
  #endif
  void set_status(const char* value);
  void set_status(const char* value, size_t size);
  ::std::string* mutable_status();
  ::std::string* release_status();
  void set_allocated_status(::std::string* status);

  // string WorkMode = 2;
  void clear_workmode();
  static const int kWorkModeFieldNumber = 2;
  const ::std::string& workmode() const;
  void set_workmode(const ::std::string& value);
  #if LANG_CXX11
  void set_workmode(::std::string&& value);
  #endif
  void set_workmode(const char* value);
  void set_workmode(const char* value, size_t size);
  ::std::string* mutable_workmode();
  ::std::string* release_workmode();
  void set_allocated_workmode(::std::string* workmode);

  // @@protoc_insertion_point(class_scope:FanPumpStatusConfig)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr status_;
  ::google::protobuf::internal::ArenaStringPtr workmode_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_fanpumpstatusconfig_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FanPumpStatusConfig

// string Status = 1;
inline void FanPumpStatusConfig::clear_status() {
  status_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& FanPumpStatusConfig::status() const {
  // @@protoc_insertion_point(field_get:FanPumpStatusConfig.Status)
  return status_.GetNoArena();
}
inline void FanPumpStatusConfig::set_status(const ::std::string& value) {
  
  status_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:FanPumpStatusConfig.Status)
}
#if LANG_CXX11
inline void FanPumpStatusConfig::set_status(::std::string&& value) {
  
  status_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:FanPumpStatusConfig.Status)
}
#endif
inline void FanPumpStatusConfig::set_status(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  status_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:FanPumpStatusConfig.Status)
}
inline void FanPumpStatusConfig::set_status(const char* value, size_t size) {
  
  status_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:FanPumpStatusConfig.Status)
}
inline ::std::string* FanPumpStatusConfig::mutable_status() {
  
  // @@protoc_insertion_point(field_mutable:FanPumpStatusConfig.Status)
  return status_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FanPumpStatusConfig::release_status() {
  // @@protoc_insertion_point(field_release:FanPumpStatusConfig.Status)
  
  return status_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FanPumpStatusConfig::set_allocated_status(::std::string* status) {
  if (status != NULL) {
    
  } else {
    
  }
  status_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), status);
  // @@protoc_insertion_point(field_set_allocated:FanPumpStatusConfig.Status)
}

// string WorkMode = 2;
inline void FanPumpStatusConfig::clear_workmode() {
  workmode_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& FanPumpStatusConfig::workmode() const {
  // @@protoc_insertion_point(field_get:FanPumpStatusConfig.WorkMode)
  return workmode_.GetNoArena();
}
inline void FanPumpStatusConfig::set_workmode(const ::std::string& value) {
  
  workmode_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:FanPumpStatusConfig.WorkMode)
}
#if LANG_CXX11
inline void FanPumpStatusConfig::set_workmode(::std::string&& value) {
  
  workmode_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:FanPumpStatusConfig.WorkMode)
}
#endif
inline void FanPumpStatusConfig::set_workmode(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  workmode_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:FanPumpStatusConfig.WorkMode)
}
inline void FanPumpStatusConfig::set_workmode(const char* value, size_t size) {
  
  workmode_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:FanPumpStatusConfig.WorkMode)
}
inline ::std::string* FanPumpStatusConfig::mutable_workmode() {
  
  // @@protoc_insertion_point(field_mutable:FanPumpStatusConfig.WorkMode)
  return workmode_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FanPumpStatusConfig::release_workmode() {
  // @@protoc_insertion_point(field_release:FanPumpStatusConfig.WorkMode)
  
  return workmode_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FanPumpStatusConfig::set_allocated_workmode(::std::string* workmode) {
  if (workmode != NULL) {
    
  } else {
    
  }
  workmode_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), workmode);
  // @@protoc_insertion_point(field_set_allocated:FanPumpStatusConfig.WorkMode)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_fanpumpstatusconfig_2eproto
