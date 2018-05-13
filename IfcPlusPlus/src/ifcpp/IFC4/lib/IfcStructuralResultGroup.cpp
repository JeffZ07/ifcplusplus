/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcAnalysisTheoryTypeEnum.h"
#include "ifcpp/IFC4/include/IfcBoolean.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcRelAggregates.h"
#include "ifcpp/IFC4/include/IfcRelAssigns.h"
#include "ifcpp/IFC4/include/IfcRelAssignsToGroup.h"
#include "ifcpp/IFC4/include/IfcRelAssociates.h"
#include "ifcpp/IFC4/include/IfcRelDeclares.h"
#include "ifcpp/IFC4/include/IfcRelDefinesByObject.h"
#include "ifcpp/IFC4/include/IfcRelDefinesByProperties.h"
#include "ifcpp/IFC4/include/IfcRelDefinesByType.h"
#include "ifcpp/IFC4/include/IfcRelNests.h"
#include "ifcpp/IFC4/include/IfcStructuralAnalysisModel.h"
#include "ifcpp/IFC4/include/IfcStructuralLoadGroup.h"
#include "ifcpp/IFC4/include/IfcStructuralResultGroup.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcStructuralResultGroup 
IfcStructuralResultGroup::IfcStructuralResultGroup() {}
IfcStructuralResultGroup::IfcStructuralResultGroup( int id ) { m_entity_id = id; }
IfcStructuralResultGroup::~IfcStructuralResultGroup() {}
shared_ptr<BuildingObject> IfcStructuralResultGroup::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcStructuralResultGroup> copy_self( new IfcStructuralResultGroup() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = shared_ptr<IfcGloballyUniqueId>(new IfcGloballyUniqueId( createGUID32_wstr().c_str() ) ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_ObjectType ) { copy_self->m_ObjectType = dynamic_pointer_cast<IfcLabel>( m_ObjectType->getDeepCopy(options) ); }
	if( m_TheoryType ) { copy_self->m_TheoryType = dynamic_pointer_cast<IfcAnalysisTheoryTypeEnum>( m_TheoryType->getDeepCopy(options) ); }
	if( m_ResultForLoadGroup ) { copy_self->m_ResultForLoadGroup = dynamic_pointer_cast<IfcStructuralLoadGroup>( m_ResultForLoadGroup->getDeepCopy(options) ); }
	if( m_IsLinear ) { copy_self->m_IsLinear = dynamic_pointer_cast<IfcBoolean>( m_IsLinear->getDeepCopy(options) ); }
	return copy_self;
}
void IfcStructuralResultGroup::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCSTRUCTURALRESULTGROUP" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_TheoryType ) { m_TheoryType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ResultForLoadGroup ) { stream << "#" << m_ResultForLoadGroup->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_IsLinear ) { m_IsLinear->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcStructuralResultGroup::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcStructuralResultGroup::toString() const { return L"IfcStructuralResultGroup"; }
void IfcStructuralResultGroup::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 8 ){ std::stringstream err; err << "Wrong parameter count for entity IfcStructuralResultGroup, expecting 8, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	m_ObjectType = IfcLabel::createObjectFromSTEP( args[4], map );
	m_TheoryType = IfcAnalysisTheoryTypeEnum::createObjectFromSTEP( args[5], map );
	readEntityReference( args[6], m_ResultForLoadGroup, map );
	m_IsLinear = IfcBoolean::createObjectFromSTEP( args[7], map );
}
void IfcStructuralResultGroup::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcGroup::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "TheoryType", m_TheoryType ) );
	vec_attributes.push_back( std::make_pair( "ResultForLoadGroup", m_ResultForLoadGroup ) );
	vec_attributes.push_back( std::make_pair( "IsLinear", m_IsLinear ) );
}
void IfcStructuralResultGroup::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcGroup::getAttributesInverse( vec_attributes_inverse );
	if( m_ResultGroupFor_inverse.size() > 0 )
	{
		shared_ptr<AttributeObjectVector> ResultGroupFor_inverse_vec_obj( new AttributeObjectVector() );
		for( size_t i=0; i<m_ResultGroupFor_inverse.size(); ++i )
		{
			if( !m_ResultGroupFor_inverse[i].expired() )
			{
				ResultGroupFor_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcStructuralAnalysisModel>( m_ResultGroupFor_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "ResultGroupFor_inverse", ResultGroupFor_inverse_vec_obj ) );
	}
}
void IfcStructuralResultGroup::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcGroup::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcStructuralResultGroup> ptr_self = dynamic_pointer_cast<IfcStructuralResultGroup>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcStructuralResultGroup::setInverseCounterparts: type mismatch" ); }
	if( m_ResultForLoadGroup )
	{
		m_ResultForLoadGroup->m_SourceOfResultGroup_inverse.push_back( ptr_self );
	}
}
void IfcStructuralResultGroup::unlinkFromInverseCounterparts()
{
	IfcGroup::unlinkFromInverseCounterparts();
	if( m_ResultForLoadGroup )
	{
		std::vector<weak_ptr<IfcStructuralResultGroup> >& SourceOfResultGroup_inverse = m_ResultForLoadGroup->m_SourceOfResultGroup_inverse;
		for( auto it_SourceOfResultGroup_inverse = SourceOfResultGroup_inverse.begin(); it_SourceOfResultGroup_inverse != SourceOfResultGroup_inverse.end(); )
		{
			weak_ptr<IfcStructuralResultGroup> self_candidate_weak = *it_SourceOfResultGroup_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_SourceOfResultGroup_inverse;
				continue;
			}
			shared_ptr<IfcStructuralResultGroup> self_candidate( *it_SourceOfResultGroup_inverse );
			if( self_candidate.get() == this )
			{
				it_SourceOfResultGroup_inverse= SourceOfResultGroup_inverse.erase( it_SourceOfResultGroup_inverse );
			}
			else
			{
				++it_SourceOfResultGroup_inverse;
			}
		}
	}
}
