// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.23.0
// 	protoc        v3.13.0
// source: trade.proto

package message

import (
	proto "github.com/golang/protobuf/proto"
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

// This is a compile-time assertion that a sufficiently up-to-date version
// of the legacy proto package is being used.
const _ = proto.ProtoPackageIsVersion4

type Trade struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Symbol string `protobuf:"bytes,1,opt,name=symbol,proto3" json:"symbol,omitempty"`
	Aaa    int32  `protobuf:"varint,2,opt,name=aaa,proto3" json:"aaa,omitempty"`
	Bbb    int32  `protobuf:"varint,3,opt,name=bbb,proto3" json:"bbb,omitempty"`
}

func (x *Trade) Reset() {
	*x = Trade{}
	if protoimpl.UnsafeEnabled {
		mi := &file_trade_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *Trade) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Trade) ProtoMessage() {}

func (x *Trade) ProtoReflect() protoreflect.Message {
	mi := &file_trade_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Trade.ProtoReflect.Descriptor instead.
func (*Trade) Descriptor() ([]byte, []int) {
	return file_trade_proto_rawDescGZIP(), []int{0}
}

func (x *Trade) GetSymbol() string {
	if x != nil {
		return x.Symbol
	}
	return ""
}

func (x *Trade) GetAaa() int32 {
	if x != nil {
		return x.Aaa
	}
	return 0
}

func (x *Trade) GetBbb() int32 {
	if x != nil {
		return x.Bbb
	}
	return 0
}

type Order struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Symbol string `protobuf:"bytes,1,opt,name=symbol,proto3" json:"symbol,omitempty"`
	Aaa    int32  `protobuf:"varint,2,opt,name=aaa,proto3" json:"aaa,omitempty"`
	Bbb    int32  `protobuf:"varint,3,opt,name=bbb,proto3" json:"bbb,omitempty"`
}

func (x *Order) Reset() {
	*x = Order{}
	if protoimpl.UnsafeEnabled {
		mi := &file_trade_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *Order) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Order) ProtoMessage() {}

func (x *Order) ProtoReflect() protoreflect.Message {
	mi := &file_trade_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Order.ProtoReflect.Descriptor instead.
func (*Order) Descriptor() ([]byte, []int) {
	return file_trade_proto_rawDescGZIP(), []int{1}
}

func (x *Order) GetSymbol() string {
	if x != nil {
		return x.Symbol
	}
	return ""
}

func (x *Order) GetAaa() int32 {
	if x != nil {
		return x.Aaa
	}
	return 0
}

func (x *Order) GetBbb() int32 {
	if x != nil {
		return x.Bbb
	}
	return 0
}

var File_trade_proto protoreflect.FileDescriptor

var file_trade_proto_rawDesc = []byte{
	0x0a, 0x0b, 0x74, 0x72, 0x61, 0x64, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x12, 0x07, 0x6d,
	0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x22, 0x43, 0x0a, 0x05, 0x54, 0x72, 0x61, 0x64, 0x65, 0x12,
	0x16, 0x0a, 0x06, 0x73, 0x79, 0x6d, 0x62, 0x6f, 0x6c, 0x18, 0x01, 0x20, 0x01, 0x28, 0x09, 0x52,
	0x06, 0x73, 0x79, 0x6d, 0x62, 0x6f, 0x6c, 0x12, 0x10, 0x0a, 0x03, 0x61, 0x61, 0x61, 0x18, 0x02,
	0x20, 0x01, 0x28, 0x05, 0x52, 0x03, 0x61, 0x61, 0x61, 0x12, 0x10, 0x0a, 0x03, 0x62, 0x62, 0x62,
	0x18, 0x03, 0x20, 0x01, 0x28, 0x05, 0x52, 0x03, 0x62, 0x62, 0x62, 0x22, 0x43, 0x0a, 0x05, 0x4f,
	0x72, 0x64, 0x65, 0x72, 0x12, 0x16, 0x0a, 0x06, 0x73, 0x79, 0x6d, 0x62, 0x6f, 0x6c, 0x18, 0x01,
	0x20, 0x01, 0x28, 0x09, 0x52, 0x06, 0x73, 0x79, 0x6d, 0x62, 0x6f, 0x6c, 0x12, 0x10, 0x0a, 0x03,
	0x61, 0x61, 0x61, 0x18, 0x02, 0x20, 0x01, 0x28, 0x05, 0x52, 0x03, 0x61, 0x61, 0x61, 0x12, 0x10,
	0x0a, 0x03, 0x62, 0x62, 0x62, 0x18, 0x03, 0x20, 0x01, 0x28, 0x05, 0x52, 0x03, 0x62, 0x62, 0x62,
	0x42, 0x0b, 0x5a, 0x09, 0x2e, 0x3b, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x62, 0x06, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_trade_proto_rawDescOnce sync.Once
	file_trade_proto_rawDescData = file_trade_proto_rawDesc
)

func file_trade_proto_rawDescGZIP() []byte {
	file_trade_proto_rawDescOnce.Do(func() {
		file_trade_proto_rawDescData = protoimpl.X.CompressGZIP(file_trade_proto_rawDescData)
	})
	return file_trade_proto_rawDescData
}

var file_trade_proto_msgTypes = make([]protoimpl.MessageInfo, 2)
var file_trade_proto_goTypes = []interface{}{
	(*Trade)(nil), // 0: message.Trade
	(*Order)(nil), // 1: message.Order
}
var file_trade_proto_depIdxs = []int32{
	0, // [0:0] is the sub-list for method output_type
	0, // [0:0] is the sub-list for method input_type
	0, // [0:0] is the sub-list for extension type_name
	0, // [0:0] is the sub-list for extension extendee
	0, // [0:0] is the sub-list for field type_name
}

func init() { file_trade_proto_init() }
func file_trade_proto_init() {
	if File_trade_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_trade_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*Trade); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_trade_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*Order); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_trade_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   2,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_trade_proto_goTypes,
		DependencyIndexes: file_trade_proto_depIdxs,
		MessageInfos:      file_trade_proto_msgTypes,
	}.Build()
	File_trade_proto = out.File
	file_trade_proto_rawDesc = nil
	file_trade_proto_goTypes = nil
	file_trade_proto_depIdxs = nil
}