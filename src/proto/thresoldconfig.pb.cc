// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: thresoldconfig.proto

#include "thresoldconfig.pb.h"

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

namespace protobuf_thresoldconfig_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_thresoldconfig_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_GasThreshold;
}  // namespace protobuf_thresoldconfig_2eproto
class GasThresholdDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<GasThreshold>
      _instance;
} _GasThreshold_default_instance_;
class GasThresholdListDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<GasThresholdList>
      _instance;
} _GasThresholdList_default_instance_;
namespace protobuf_thresoldconfig_2eproto {
static void InitDefaultsGasThreshold() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_GasThreshold_default_instance_;
    new (ptr) ::GasThreshold();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::GasThreshold::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_GasThreshold =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsGasThreshold}, {}};

static void InitDefaultsGasThresholdList() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_GasThresholdList_default_instance_;
    new (ptr) ::GasThresholdList();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::GasThresholdList::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_GasThresholdList =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsGasThresholdList}, {
      &protobuf_thresoldconfig_2eproto::scc_info_GasThreshold.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_GasThreshold.base);
  ::google::protobuf::internal::InitSCC(&scc_info_GasThresholdList.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GasThreshold, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GasThreshold, name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GasThreshold, thresholdl_max1_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GasThreshold, thresholdl_max2_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GasThreshold, thresholdl_max3_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GasThreshold, thresholdl_min1_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GasThreshold, thresholdl_min2_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GasThreshold, thresholdl_min3_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GasThreshold, thresholdchange_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GasThresholdList, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GasThresholdList, thresholds_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::GasThreshold)},
  { 13, -1, sizeof(::GasThresholdList)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_GasThreshold_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::_GasThresholdList_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "thresoldconfig.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\024thresoldconfig.proto\"\313\001\n\014GasThreshold\022"
      "\014\n\004Name\030\001 \001(\t\022\027\n\017ThresholdL_Max1\030\002 \001(\002\022\027"
      "\n\017ThresholdL_Max2\030\003 \001(\002\022\027\n\017ThresholdL_Ma"
      "x3\030\004 \001(\002\022\027\n\017ThresholdL_Min1\030\005 \001(\002\022\027\n\017Thr"
      "esholdL_Min2\030\006 \001(\002\022\027\n\017ThresholdL_Min3\030\007 "
      "\001(\002\022\027\n\017ThresholdChange\030\010 \001(\002\"5\n\020GasThres"
      "holdList\022!\n\nthresholds\030\001 \003(\0132\r.GasThresh"
      "oldb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 291);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "thresoldconfig.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_thresoldconfig_2eproto

// ===================================================================

void GasThreshold::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GasThreshold::kNameFieldNumber;
const int GasThreshold::kThresholdLMax1FieldNumber;
const int GasThreshold::kThresholdLMax2FieldNumber;
const int GasThreshold::kThresholdLMax3FieldNumber;
const int GasThreshold::kThresholdLMin1FieldNumber;
const int GasThreshold::kThresholdLMin2FieldNumber;
const int GasThreshold::kThresholdLMin3FieldNumber;
const int GasThreshold::kThresholdChangeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GasThreshold::GasThreshold()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_thresoldconfig_2eproto::scc_info_GasThreshold.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:GasThreshold)
}
GasThreshold::GasThreshold(const GasThreshold& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.name().size() > 0) {
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  ::memcpy(&thresholdl_max1_, &from.thresholdl_max1_,
    static_cast<size_t>(reinterpret_cast<char*>(&thresholdchange_) -
    reinterpret_cast<char*>(&thresholdl_max1_)) + sizeof(thresholdchange_));
  // @@protoc_insertion_point(copy_constructor:GasThreshold)
}

void GasThreshold::SharedCtor() {
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&thresholdl_max1_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&thresholdchange_) -
      reinterpret_cast<char*>(&thresholdl_max1_)) + sizeof(thresholdchange_));
}

GasThreshold::~GasThreshold() {
  // @@protoc_insertion_point(destructor:GasThreshold)
  SharedDtor();
}

void GasThreshold::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void GasThreshold::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* GasThreshold::descriptor() {
  ::protobuf_thresoldconfig_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_thresoldconfig_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const GasThreshold& GasThreshold::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_thresoldconfig_2eproto::scc_info_GasThreshold.base);
  return *internal_default_instance();
}


void GasThreshold::Clear() {
// @@protoc_insertion_point(message_clear_start:GasThreshold)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&thresholdl_max1_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&thresholdchange_) -
      reinterpret_cast<char*>(&thresholdl_max1_)) + sizeof(thresholdchange_));
  _internal_metadata_.Clear();
}

bool GasThreshold::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:GasThreshold)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string Name = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->name().data(), static_cast<int>(this->name().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "GasThreshold.Name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // float ThresholdL_Max1 = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(21u /* 21 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &thresholdl_max1_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // float ThresholdL_Max2 = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(29u /* 29 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &thresholdl_max2_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // float ThresholdL_Max3 = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(37u /* 37 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &thresholdl_max3_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // float ThresholdL_Min1 = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(45u /* 45 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &thresholdl_min1_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // float ThresholdL_Min2 = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(53u /* 53 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &thresholdl_min2_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // float ThresholdL_Min3 = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(61u /* 61 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &thresholdl_min3_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // float ThresholdChange = 8;
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(69u /* 69 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &thresholdchange_)));
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
  // @@protoc_insertion_point(parse_success:GasThreshold)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:GasThreshold)
  return false;
#undef DO_
}

void GasThreshold::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:GasThreshold)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string Name = 1;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "GasThreshold.Name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->name(), output);
  }

  // float ThresholdL_Max1 = 2;
  if (this->thresholdl_max1() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(2, this->thresholdl_max1(), output);
  }

  // float ThresholdL_Max2 = 3;
  if (this->thresholdl_max2() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(3, this->thresholdl_max2(), output);
  }

  // float ThresholdL_Max3 = 4;
  if (this->thresholdl_max3() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(4, this->thresholdl_max3(), output);
  }

  // float ThresholdL_Min1 = 5;
  if (this->thresholdl_min1() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(5, this->thresholdl_min1(), output);
  }

  // float ThresholdL_Min2 = 6;
  if (this->thresholdl_min2() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(6, this->thresholdl_min2(), output);
  }

  // float ThresholdL_Min3 = 7;
  if (this->thresholdl_min3() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(7, this->thresholdl_min3(), output);
  }

  // float ThresholdChange = 8;
  if (this->thresholdchange() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(8, this->thresholdchange(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:GasThreshold)
}

::google::protobuf::uint8* GasThreshold::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:GasThreshold)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string Name = 1;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "GasThreshold.Name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  // float ThresholdL_Max1 = 2;
  if (this->thresholdl_max1() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(2, this->thresholdl_max1(), target);
  }

  // float ThresholdL_Max2 = 3;
  if (this->thresholdl_max2() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(3, this->thresholdl_max2(), target);
  }

  // float ThresholdL_Max3 = 4;
  if (this->thresholdl_max3() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(4, this->thresholdl_max3(), target);
  }

  // float ThresholdL_Min1 = 5;
  if (this->thresholdl_min1() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(5, this->thresholdl_min1(), target);
  }

  // float ThresholdL_Min2 = 6;
  if (this->thresholdl_min2() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(6, this->thresholdl_min2(), target);
  }

  // float ThresholdL_Min3 = 7;
  if (this->thresholdl_min3() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(7, this->thresholdl_min3(), target);
  }

  // float ThresholdChange = 8;
  if (this->thresholdchange() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(8, this->thresholdchange(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:GasThreshold)
  return target;
}

size_t GasThreshold::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:GasThreshold)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string Name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  // float ThresholdL_Max1 = 2;
  if (this->thresholdl_max1() != 0) {
    total_size += 1 + 4;
  }

  // float ThresholdL_Max2 = 3;
  if (this->thresholdl_max2() != 0) {
    total_size += 1 + 4;
  }

  // float ThresholdL_Max3 = 4;
  if (this->thresholdl_max3() != 0) {
    total_size += 1 + 4;
  }

  // float ThresholdL_Min1 = 5;
  if (this->thresholdl_min1() != 0) {
    total_size += 1 + 4;
  }

  // float ThresholdL_Min2 = 6;
  if (this->thresholdl_min2() != 0) {
    total_size += 1 + 4;
  }

  // float ThresholdL_Min3 = 7;
  if (this->thresholdl_min3() != 0) {
    total_size += 1 + 4;
  }

  // float ThresholdChange = 8;
  if (this->thresholdchange() != 0) {
    total_size += 1 + 4;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GasThreshold::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:GasThreshold)
  GOOGLE_DCHECK_NE(&from, this);
  const GasThreshold* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const GasThreshold>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:GasThreshold)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:GasThreshold)
    MergeFrom(*source);
  }
}

void GasThreshold::MergeFrom(const GasThreshold& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:GasThreshold)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.thresholdl_max1() != 0) {
    set_thresholdl_max1(from.thresholdl_max1());
  }
  if (from.thresholdl_max2() != 0) {
    set_thresholdl_max2(from.thresholdl_max2());
  }
  if (from.thresholdl_max3() != 0) {
    set_thresholdl_max3(from.thresholdl_max3());
  }
  if (from.thresholdl_min1() != 0) {
    set_thresholdl_min1(from.thresholdl_min1());
  }
  if (from.thresholdl_min2() != 0) {
    set_thresholdl_min2(from.thresholdl_min2());
  }
  if (from.thresholdl_min3() != 0) {
    set_thresholdl_min3(from.thresholdl_min3());
  }
  if (from.thresholdchange() != 0) {
    set_thresholdchange(from.thresholdchange());
  }
}

void GasThreshold::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:GasThreshold)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GasThreshold::CopyFrom(const GasThreshold& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GasThreshold)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GasThreshold::IsInitialized() const {
  return true;
}

void GasThreshold::Swap(GasThreshold* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GasThreshold::InternalSwap(GasThreshold* other) {
  using std::swap;
  name_.Swap(&other->name_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(thresholdl_max1_, other->thresholdl_max1_);
  swap(thresholdl_max2_, other->thresholdl_max2_);
  swap(thresholdl_max3_, other->thresholdl_max3_);
  swap(thresholdl_min1_, other->thresholdl_min1_);
  swap(thresholdl_min2_, other->thresholdl_min2_);
  swap(thresholdl_min3_, other->thresholdl_min3_);
  swap(thresholdchange_, other->thresholdchange_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata GasThreshold::GetMetadata() const {
  protobuf_thresoldconfig_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_thresoldconfig_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void GasThresholdList::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GasThresholdList::kThresholdsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GasThresholdList::GasThresholdList()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_thresoldconfig_2eproto::scc_info_GasThresholdList.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:GasThresholdList)
}
GasThresholdList::GasThresholdList(const GasThresholdList& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      thresholds_(from.thresholds_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:GasThresholdList)
}

void GasThresholdList::SharedCtor() {
}

GasThresholdList::~GasThresholdList() {
  // @@protoc_insertion_point(destructor:GasThresholdList)
  SharedDtor();
}

void GasThresholdList::SharedDtor() {
}

void GasThresholdList::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* GasThresholdList::descriptor() {
  ::protobuf_thresoldconfig_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_thresoldconfig_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const GasThresholdList& GasThresholdList::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_thresoldconfig_2eproto::scc_info_GasThresholdList.base);
  return *internal_default_instance();
}


void GasThresholdList::Clear() {
// @@protoc_insertion_point(message_clear_start:GasThresholdList)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  thresholds_.Clear();
  _internal_metadata_.Clear();
}

bool GasThresholdList::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:GasThresholdList)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .GasThreshold thresholds = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_thresholds()));
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
  // @@protoc_insertion_point(parse_success:GasThresholdList)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:GasThresholdList)
  return false;
#undef DO_
}

void GasThresholdList::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:GasThresholdList)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .GasThreshold thresholds = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->thresholds_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1,
      this->thresholds(static_cast<int>(i)),
      output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:GasThresholdList)
}

::google::protobuf::uint8* GasThresholdList::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:GasThresholdList)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .GasThreshold thresholds = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->thresholds_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->thresholds(static_cast<int>(i)), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:GasThresholdList)
  return target;
}

size_t GasThresholdList::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:GasThresholdList)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .GasThreshold thresholds = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->thresholds_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->thresholds(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GasThresholdList::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:GasThresholdList)
  GOOGLE_DCHECK_NE(&from, this);
  const GasThresholdList* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const GasThresholdList>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:GasThresholdList)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:GasThresholdList)
    MergeFrom(*source);
  }
}

void GasThresholdList::MergeFrom(const GasThresholdList& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:GasThresholdList)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  thresholds_.MergeFrom(from.thresholds_);
}

void GasThresholdList::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:GasThresholdList)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GasThresholdList::CopyFrom(const GasThresholdList& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GasThresholdList)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GasThresholdList::IsInitialized() const {
  return true;
}

void GasThresholdList::Swap(GasThresholdList* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GasThresholdList::InternalSwap(GasThresholdList* other) {
  using std::swap;
  CastToBase(&thresholds_)->InternalSwap(CastToBase(&other->thresholds_));
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata GasThresholdList::GetMetadata() const {
  protobuf_thresoldconfig_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_thresoldconfig_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::GasThreshold* Arena::CreateMaybeMessage< ::GasThreshold >(Arena* arena) {
  return Arena::CreateInternal< ::GasThreshold >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::GasThresholdList* Arena::CreateMaybeMessage< ::GasThresholdList >(Arena* arena) {
  return Arena::CreateInternal< ::GasThresholdList >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
