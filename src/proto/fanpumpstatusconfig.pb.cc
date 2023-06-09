// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: fanpumpstatusconfig.proto

#include "fanpumpstatusconfig.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

class FanPumpStatusConfigDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<FanPumpStatusConfig>
      _instance;
} _FanPumpStatusConfig_default_instance_;
namespace protobuf_fanpumpstatusconfig_2eproto {
static void InitDefaultsFanPumpStatusConfig() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_FanPumpStatusConfig_default_instance_;
    new (ptr) ::FanPumpStatusConfig();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::FanPumpStatusConfig::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_FanPumpStatusConfig =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsFanPumpStatusConfig}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_FanPumpStatusConfig.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::FanPumpStatusConfig, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::FanPumpStatusConfig, status_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::FanPumpStatusConfig, workmode_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::FanPumpStatusConfig)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_FanPumpStatusConfig_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "fanpumpstatusconfig.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\031fanpumpstatusconfig.proto\"7\n\023FanPumpSt"
      "atusConfig\022\016\n\006Status\030\001 \001(\t\022\020\n\010WorkMode\030\002"
      " \001(\tb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 92);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "fanpumpstatusconfig.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_fanpumpstatusconfig_2eproto

// ===================================================================

void FanPumpStatusConfig::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int FanPumpStatusConfig::kStatusFieldNumber;
const int FanPumpStatusConfig::kWorkModeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

FanPumpStatusConfig::FanPumpStatusConfig()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_fanpumpstatusconfig_2eproto::scc_info_FanPumpStatusConfig.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:FanPumpStatusConfig)
}
FanPumpStatusConfig::FanPumpStatusConfig(const FanPumpStatusConfig& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  status_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.status().size() > 0) {
    status_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.status_);
  }
  workmode_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.workmode().size() > 0) {
    workmode_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.workmode_);
  }
  // @@protoc_insertion_point(copy_constructor:FanPumpStatusConfig)
}

void FanPumpStatusConfig::SharedCtor() {
  status_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  workmode_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

FanPumpStatusConfig::~FanPumpStatusConfig() {
  // @@protoc_insertion_point(destructor:FanPumpStatusConfig)
  SharedDtor();
}

void FanPumpStatusConfig::SharedDtor() {
  status_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  workmode_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void FanPumpStatusConfig::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* FanPumpStatusConfig::descriptor() {
  ::protobuf_fanpumpstatusconfig_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_fanpumpstatusconfig_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const FanPumpStatusConfig& FanPumpStatusConfig::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_fanpumpstatusconfig_2eproto::scc_info_FanPumpStatusConfig.base);
  return *internal_default_instance();
}


void FanPumpStatusConfig::Clear() {
// @@protoc_insertion_point(message_clear_start:FanPumpStatusConfig)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  status_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  workmode_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool FanPumpStatusConfig::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:FanPumpStatusConfig)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string Status = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_status()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->status().data(), static_cast<int>(this->status().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "FanPumpStatusConfig.Status"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string WorkMode = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_workmode()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->workmode().data(), static_cast<int>(this->workmode().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "FanPumpStatusConfig.WorkMode"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:FanPumpStatusConfig)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:FanPumpStatusConfig)
  return false;
#undef DO_
}

void FanPumpStatusConfig::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:FanPumpStatusConfig)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string Status = 1;
  if (this->status().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->status().data(), static_cast<int>(this->status().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "FanPumpStatusConfig.Status");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->status(), output);
  }

  // string WorkMode = 2;
  if (this->workmode().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->workmode().data(), static_cast<int>(this->workmode().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "FanPumpStatusConfig.WorkMode");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->workmode(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:FanPumpStatusConfig)
}

::google::protobuf::uint8* FanPumpStatusConfig::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:FanPumpStatusConfig)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string Status = 1;
  if (this->status().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->status().data(), static_cast<int>(this->status().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "FanPumpStatusConfig.Status");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->status(), target);
  }

  // string WorkMode = 2;
  if (this->workmode().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->workmode().data(), static_cast<int>(this->workmode().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "FanPumpStatusConfig.WorkMode");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->workmode(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:FanPumpStatusConfig)
  return target;
}

size_t FanPumpStatusConfig::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:FanPumpStatusConfig)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string Status = 1;
  if (this->status().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->status());
  }

  // string WorkMode = 2;
  if (this->workmode().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->workmode());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void FanPumpStatusConfig::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:FanPumpStatusConfig)
  GOOGLE_DCHECK_NE(&from, this);
  const FanPumpStatusConfig* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const FanPumpStatusConfig>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:FanPumpStatusConfig)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:FanPumpStatusConfig)
    MergeFrom(*source);
  }
}

void FanPumpStatusConfig::MergeFrom(const FanPumpStatusConfig& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:FanPumpStatusConfig)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.status().size() > 0) {

    status_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.status_);
  }
  if (from.workmode().size() > 0) {

    workmode_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.workmode_);
  }
}

void FanPumpStatusConfig::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:FanPumpStatusConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FanPumpStatusConfig::CopyFrom(const FanPumpStatusConfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:FanPumpStatusConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FanPumpStatusConfig::IsInitialized() const {
  return true;
}

void FanPumpStatusConfig::Swap(FanPumpStatusConfig* other) {
  if (other == this) return;
  InternalSwap(other);
}
void FanPumpStatusConfig::InternalSwap(FanPumpStatusConfig* other) {
  using std::swap;
  status_.Swap(&other->status_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  workmode_.Swap(&other->workmode_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata FanPumpStatusConfig::GetMetadata() const {
  protobuf_fanpumpstatusconfig_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_fanpumpstatusconfig_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::FanPumpStatusConfig* Arena::CreateMaybeMessage< ::FanPumpStatusConfig >(Arena* arena) {
  return Arena::CreateInternal< ::FanPumpStatusConfig >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
