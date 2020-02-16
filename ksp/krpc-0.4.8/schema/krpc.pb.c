/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.1 at Sun Oct 28 12:06:41 2018. */

#include "krpc.pb.h/krpc.pb.h"
/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t krpc_schema_ConnectionRequest_fields[4] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, krpc_schema_ConnectionRequest, type, type, 0),
    PB_FIELD(  2, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_ConnectionRequest, client_name, type, 0),
    PB_FIELD(  3, BYTES   , SINGULAR, CALLBACK, OTHER, krpc_schema_ConnectionRequest, client_identifier, client_name, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_ConnectionResponse_fields[4] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, krpc_schema_ConnectionResponse, status, status, 0),
    PB_FIELD(  2, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_ConnectionResponse, message, status, 0),
    PB_FIELD(  3, BYTES   , SINGULAR, CALLBACK, OTHER, krpc_schema_ConnectionResponse, client_identifier, message, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Request_fields[2] = {
    PB_FIELD(  1, MESSAGE , REPEATED, STATIC  , FIRST, krpc_schema_Request, calls, calls, &krpc_schema_ProcedureCall_fields),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_ProcedureCall_fields[4] = {
    PB_FIELD(  3, MESSAGE , REPEATED, CALLBACK, FIRST, krpc_schema_ProcedureCall, arguments, arguments, &krpc_schema_Argument_fields),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, krpc_schema_ProcedureCall, service_id, arguments, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, krpc_schema_ProcedureCall, procedure_id, service_id, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Argument_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, krpc_schema_Argument, position, position, 0),
    PB_FIELD(  2, BYTES   , SINGULAR, CALLBACK, OTHER, krpc_schema_Argument, value, position, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Response_fields[3] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, CALLBACK, FIRST, krpc_schema_Response, error, error, &krpc_schema_Error_fields),
    PB_FIELD(  2, MESSAGE , REPEATED, STATIC  , OTHER, krpc_schema_Response, results, error, &krpc_schema_ProcedureResult_fields),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_ProcedureResult_fields[3] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, CALLBACK, FIRST, krpc_schema_ProcedureResult, error, error, &krpc_schema_Error_fields),
    PB_FIELD(  2, BYTES   , SINGULAR, CALLBACK, OTHER, krpc_schema_ProcedureResult, value, error, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Error_fields[5] = {
    PB_FIELD(  1, STRING  , SINGULAR, CALLBACK, FIRST, krpc_schema_Error, service, service, 0),
    PB_FIELD(  2, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_Error, name, service, 0),
    PB_FIELD(  3, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_Error, description, name, 0),
    PB_FIELD(  4, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_Error, stack_trace, description, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_StreamUpdate_fields[2] = {
    PB_FIELD(  1, MESSAGE , REPEATED, CALLBACK, FIRST, krpc_schema_StreamUpdate, results, results, &krpc_schema_StreamResult_fields),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_StreamResult_fields[3] = {
    PB_FIELD(  1, UINT64  , SINGULAR, STATIC  , FIRST, krpc_schema_StreamResult, id, id, 0),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, krpc_schema_StreamResult, result, id, &krpc_schema_ProcedureResult_fields),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Services_fields[2] = {
    PB_FIELD(  1, MESSAGE , REPEATED, CALLBACK, FIRST, krpc_schema_Services, services, services, &krpc_schema_Service_fields),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Service_fields[7] = {
    PB_FIELD(  1, STRING  , SINGULAR, CALLBACK, FIRST, krpc_schema_Service, name, name, 0),
    PB_FIELD(  2, MESSAGE , REPEATED, CALLBACK, OTHER, krpc_schema_Service, procedures, name, &krpc_schema_Procedure_fields),
    PB_FIELD(  3, MESSAGE , REPEATED, CALLBACK, OTHER, krpc_schema_Service, classes, procedures, &krpc_schema_Class_fields),
    PB_FIELD(  4, MESSAGE , REPEATED, CALLBACK, OTHER, krpc_schema_Service, enumerations, classes, &krpc_schema_Enumeration_fields),
    PB_FIELD(  5, MESSAGE , REPEATED, CALLBACK, OTHER, krpc_schema_Service, exceptions, enumerations, &krpc_schema_Exception_fields),
    PB_FIELD(  6, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_Service, documentation, exceptions, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Procedure_fields[7] = {
    PB_FIELD(  1, STRING  , SINGULAR, CALLBACK, FIRST, krpc_schema_Procedure, name, name, 0),
    PB_FIELD(  2, MESSAGE , REPEATED, CALLBACK, OTHER, krpc_schema_Procedure, parameters, name, &krpc_schema_Parameter_fields),
    PB_FIELD(  3, MESSAGE , SINGULAR, STATIC  , OTHER, krpc_schema_Procedure, return_type, parameters, &krpc_schema_Type_fields),
    PB_FIELD(  4, BOOL    , SINGULAR, STATIC  , OTHER, krpc_schema_Procedure, return_is_nullable, return_type, 0),
    PB_FIELD(  5, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_Procedure, documentation, return_is_nullable, 0),
    PB_FIELD(  6, UENUM   , REPEATED, CALLBACK, OTHER, krpc_schema_Procedure, game_scenes, documentation, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Parameter_fields[4] = {
    PB_FIELD(  1, STRING  , SINGULAR, CALLBACK, FIRST, krpc_schema_Parameter, name, name, 0),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, krpc_schema_Parameter, type, name, &krpc_schema_Type_fields),
    PB_FIELD(  3, BYTES   , SINGULAR, CALLBACK, OTHER, krpc_schema_Parameter, default_value, type, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Class_fields[3] = {
    PB_FIELD(  1, STRING  , SINGULAR, CALLBACK, FIRST, krpc_schema_Class, name, name, 0),
    PB_FIELD(  2, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_Class, documentation, name, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Enumeration_fields[4] = {
    PB_FIELD(  1, STRING  , SINGULAR, CALLBACK, FIRST, krpc_schema_Enumeration, name, name, 0),
    PB_FIELD(  2, MESSAGE , REPEATED, CALLBACK, OTHER, krpc_schema_Enumeration, values, name, &krpc_schema_EnumerationValue_fields),
    PB_FIELD(  3, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_Enumeration, documentation, values, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_EnumerationValue_fields[4] = {
    PB_FIELD(  1, STRING  , SINGULAR, CALLBACK, FIRST, krpc_schema_EnumerationValue, name, name, 0),
    PB_FIELD(  2, INT32   , SINGULAR, STATIC  , OTHER, krpc_schema_EnumerationValue, value, name, 0),
    PB_FIELD(  3, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_EnumerationValue, documentation, value, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Exception_fields[3] = {
    PB_FIELD(  1, STRING  , SINGULAR, CALLBACK, FIRST, krpc_schema_Exception, name, name, 0),
    PB_FIELD(  2, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_Exception, documentation, name, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Type_fields[5] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, krpc_schema_Type, code, code, 0),
    PB_FIELD(  2, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_Type, service, code, 0),
    PB_FIELD(  3, STRING  , SINGULAR, CALLBACK, OTHER, krpc_schema_Type, name, service, 0),
    PB_FIELD(  4, MESSAGE , REPEATED, CALLBACK, OTHER, krpc_schema_Type, types, name, &krpc_schema_Type_fields),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Tuple_fields[2] = {
    PB_FIELD(  1, BYTES   , REPEATED, CALLBACK, FIRST, krpc_schema_Tuple, items, items, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_List_fields[2] = {
    PB_FIELD(  1, BYTES   , REPEATED, CALLBACK, FIRST, krpc_schema_List, items, items, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Set_fields[2] = {
    PB_FIELD(  1, BYTES   , REPEATED, CALLBACK, FIRST, krpc_schema_Set, items, items, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Dictionary_fields[2] = {
    PB_FIELD(  1, MESSAGE , REPEATED, CALLBACK, FIRST, krpc_schema_Dictionary, entries, entries, &krpc_schema_DictionaryEntry_fields),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_DictionaryEntry_fields[3] = {
    PB_FIELD(  1, BYTES   , SINGULAR, CALLBACK, FIRST, krpc_schema_DictionaryEntry, key, key, 0),
    PB_FIELD(  2, BYTES   , SINGULAR, CALLBACK, OTHER, krpc_schema_DictionaryEntry, value, key, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Stream_fields[2] = {
    PB_FIELD(  1, UINT64  , SINGULAR, STATIC  , FIRST, krpc_schema_Stream, id, id, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Event_fields[2] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, krpc_schema_Event, stream, stream, &krpc_schema_Stream_fields),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_Status_fields[20] = {
    PB_FIELD(  1, STRING  , SINGULAR, STATIC  , FIRST, krpc_schema_Status, version, version, 0),
    PB_FIELD(  2, UINT64  , SINGULAR, STATIC  , OTHER, krpc_schema_Status, bytes_read, version, 0),
    PB_FIELD(  3, UINT64  , SINGULAR, STATIC  , OTHER, krpc_schema_Status, bytes_written, bytes_read, 0),
    PB_FIELD(  4, FLOAT   , SINGULAR, STATIC  , OTHER, krpc_schema_Status, bytes_read_rate, bytes_written, 0),
    PB_FIELD(  5, FLOAT   , SINGULAR, STATIC  , OTHER, krpc_schema_Status, bytes_written_rate, bytes_read_rate, 0),
    PB_FIELD(  6, UINT64  , SINGULAR, STATIC  , OTHER, krpc_schema_Status, rpcs_executed, bytes_written_rate, 0),
    PB_FIELD(  7, FLOAT   , SINGULAR, STATIC  , OTHER, krpc_schema_Status, rpc_rate, rpcs_executed, 0),
    PB_FIELD(  8, BOOL    , SINGULAR, STATIC  , OTHER, krpc_schema_Status, one_rpc_per_update, rpc_rate, 0),
    PB_FIELD(  9, UINT32  , SINGULAR, STATIC  , OTHER, krpc_schema_Status, max_time_per_update, one_rpc_per_update, 0),
    PB_FIELD( 10, BOOL    , SINGULAR, STATIC  , OTHER, krpc_schema_Status, adaptive_rate_control, max_time_per_update, 0),
    PB_FIELD( 11, BOOL    , SINGULAR, STATIC  , OTHER, krpc_schema_Status, blocking_recv, adaptive_rate_control, 0),
    PB_FIELD( 12, UINT32  , SINGULAR, STATIC  , OTHER, krpc_schema_Status, recv_timeout, blocking_recv, 0),
    PB_FIELD( 13, FLOAT   , SINGULAR, STATIC  , OTHER, krpc_schema_Status, time_per_rpc_update, recv_timeout, 0),
    PB_FIELD( 14, FLOAT   , SINGULAR, STATIC  , OTHER, krpc_schema_Status, poll_time_per_rpc_update, time_per_rpc_update, 0),
    PB_FIELD( 15, FLOAT   , SINGULAR, STATIC  , OTHER, krpc_schema_Status, exec_time_per_rpc_update, poll_time_per_rpc_update, 0),
    PB_FIELD( 16, UINT32  , SINGULAR, STATIC  , OTHER, krpc_schema_Status, stream_rpcs, exec_time_per_rpc_update, 0),
    PB_FIELD( 17, UINT64  , SINGULAR, STATIC  , OTHER, krpc_schema_Status, stream_rpcs_executed, stream_rpcs, 0),
    PB_FIELD( 18, FLOAT   , SINGULAR, STATIC  , OTHER, krpc_schema_Status, stream_rpc_rate, stream_rpcs_executed, 0),
    PB_FIELD( 19, FLOAT   , SINGULAR, STATIC  , OTHER, krpc_schema_Status, time_per_stream_update, stream_rpc_rate, 0),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_MultiplexedRequest_fields[3] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, krpc_schema_MultiplexedRequest, connection_request, connection_request, &krpc_schema_ConnectionRequest_fields),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, krpc_schema_MultiplexedRequest, request, connection_request, &krpc_schema_Request_fields),
    PB_LAST_FIELD
};

const pb_field_t krpc_schema_MultiplexedResponse_fields[3] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, krpc_schema_MultiplexedResponse, response, response, &krpc_schema_Response_fields),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, krpc_schema_MultiplexedResponse, stream_update, response, &krpc_schema_StreamUpdate_fields),
    PB_LAST_FIELD
};






/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(krpc_schema_Request, calls[0]) < 65536 && pb_membersize(krpc_schema_Response, results[0]) < 65536 && pb_membersize(krpc_schema_StreamResult, result) < 65536 && pb_membersize(krpc_schema_Procedure, return_type) < 65536 && pb_membersize(krpc_schema_Parameter, type) < 65536 && pb_membersize(krpc_schema_Event, stream) < 65536 && pb_membersize(krpc_schema_MultiplexedRequest, connection_request) < 65536 && pb_membersize(krpc_schema_MultiplexedRequest, request) < 65536 && pb_membersize(krpc_schema_MultiplexedResponse, response) < 65536 && pb_membersize(krpc_schema_MultiplexedResponse, stream_update) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_krpc_schema_ConnectionRequest_krpc_schema_ConnectionResponse_krpc_schema_Request_krpc_schema_ProcedureCall_krpc_schema_Argument_krpc_schema_Response_krpc_schema_ProcedureResult_krpc_schema_Error_krpc_schema_StreamUpdate_krpc_schema_StreamResult_krpc_schema_Services_krpc_schema_Service_krpc_schema_Procedure_krpc_schema_Parameter_krpc_schema_Class_krpc_schema_Enumeration_krpc_schema_EnumerationValue_krpc_schema_Exception_krpc_schema_Type_krpc_schema_Tuple_krpc_schema_List_krpc_schema_Set_krpc_schema_Dictionary_krpc_schema_DictionaryEntry_krpc_schema_Stream_krpc_schema_Event_krpc_schema_Status_krpc_schema_MultiplexedRequest_krpc_schema_MultiplexedResponse)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(krpc_schema_Request, calls[0]) < 256 && pb_membersize(krpc_schema_Response, results[0]) < 256 && pb_membersize(krpc_schema_StreamResult, result) < 256 && pb_membersize(krpc_schema_Procedure, return_type) < 256 && pb_membersize(krpc_schema_Parameter, type) < 256 && pb_membersize(krpc_schema_Event, stream) < 256 && pb_membersize(krpc_schema_MultiplexedRequest, connection_request) < 256 && pb_membersize(krpc_schema_MultiplexedRequest, request) < 256 && pb_membersize(krpc_schema_MultiplexedResponse, response) < 256 && pb_membersize(krpc_schema_MultiplexedResponse, stream_update) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_krpc_schema_ConnectionRequest_krpc_schema_ConnectionResponse_krpc_schema_Request_krpc_schema_ProcedureCall_krpc_schema_Argument_krpc_schema_Response_krpc_schema_ProcedureResult_krpc_schema_Error_krpc_schema_StreamUpdate_krpc_schema_StreamResult_krpc_schema_Services_krpc_schema_Service_krpc_schema_Procedure_krpc_schema_Parameter_krpc_schema_Class_krpc_schema_Enumeration_krpc_schema_EnumerationValue_krpc_schema_Exception_krpc_schema_Type_krpc_schema_Tuple_krpc_schema_List_krpc_schema_Set_krpc_schema_Dictionary_krpc_schema_DictionaryEntry_krpc_schema_Stream_krpc_schema_Event_krpc_schema_Status_krpc_schema_MultiplexedRequest_krpc_schema_MultiplexedResponse)
#endif


/* @@protoc_insertion_point(eof) */
