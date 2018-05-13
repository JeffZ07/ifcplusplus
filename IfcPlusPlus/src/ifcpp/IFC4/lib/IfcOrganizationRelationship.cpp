/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOrganization.h"
#include "ifcpp/IFC4/include/IfcOrganizationRelationship.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcOrganizationRelationship 
IfcOrganizationRelationship::IfcOrganizationRelationship() {}
IfcOrganizationRelationship::IfcOrganizationRelationship( int id ) { m_entity_id = id; }
IfcOrganizationRelationship::~IfcOrganizationRelationship() {}
shared_ptr<BuildingObject> IfcOrganizationRelationship::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcOrganizationRelationship> copy_self( new IfcOrganizationRelationship() );
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_RelatingOrganization ) { copy_self->m_RelatingOrganization = dynamic_pointer_cast<IfcOrganization>( m_RelatingOrganization->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_RelatedOrganizations.size(); ++ii )
	{
		auto item_ii = m_RelatedOrganizations[ii];
		if( item_ii )
		{
			copy_self->m_RelatedOrganizations.push_back( dynamic_pointer_cast<IfcOrganization>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IfcOrganizationRelationship::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCORGANIZATIONRELATIONSHIP" << "(";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_RelatingOrganization ) { stream << "#" << m_RelatingOrganization->m_entity_id; } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_RelatedOrganizations );
	stream << ");";
}
void IfcOrganizationRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcOrganizationRelationship::toString() const { return L"IfcOrganizationRelationship"; }
void IfcOrganizationRelationship::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 4 ){ std::stringstream err; err << "Wrong parameter count for entity IfcOrganizationRelationship, expecting 4, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_Name = IfcLabel::createObjectFromSTEP( args[0], map );
	m_Description = IfcText::createObjectFromSTEP( args[1], map );
	readEntityReference( args[2], m_RelatingOrganization, map );
	readEntityReferenceList( args[3], m_RelatedOrganizations, map );
}
void IfcOrganizationRelationship::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcResourceLevelRelationship::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "RelatingOrganization", m_RelatingOrganization ) );
	if( m_RelatedOrganizations.size() > 0 )
	{
		shared_ptr<AttributeObjectVector> RelatedOrganizations_vec_object( new AttributeObjectVector() );
		std::copy( m_RelatedOrganizations.begin(), m_RelatedOrganizations.end(), std::back_inserter( RelatedOrganizations_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "RelatedOrganizations", RelatedOrganizations_vec_object ) );
	}
}
void IfcOrganizationRelationship::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcResourceLevelRelationship::getAttributesInverse( vec_attributes_inverse );
}
void IfcOrganizationRelationship::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcResourceLevelRelationship::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcOrganizationRelationship> ptr_self = dynamic_pointer_cast<IfcOrganizationRelationship>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcOrganizationRelationship::setInverseCounterparts: type mismatch" ); }
	for( size_t i=0; i<m_RelatedOrganizations.size(); ++i )
	{
		if( m_RelatedOrganizations[i] )
		{
			m_RelatedOrganizations[i]->m_IsRelatedBy_inverse.push_back( ptr_self );
		}
	}
	if( m_RelatingOrganization )
	{
		m_RelatingOrganization->m_Relates_inverse.push_back( ptr_self );
	}
}
void IfcOrganizationRelationship::unlinkFromInverseCounterparts()
{
	IfcResourceLevelRelationship::unlinkFromInverseCounterparts();
	for( size_t i=0; i<m_RelatedOrganizations.size(); ++i )
	{
		if( m_RelatedOrganizations[i] )
		{
			std::vector<weak_ptr<IfcOrganizationRelationship> >& IsRelatedBy_inverse = m_RelatedOrganizations[i]->m_IsRelatedBy_inverse;
			for( auto it_IsRelatedBy_inverse = IsRelatedBy_inverse.begin(); it_IsRelatedBy_inverse != IsRelatedBy_inverse.end(); )
			{
				weak_ptr<IfcOrganizationRelationship> self_candidate_weak = *it_IsRelatedBy_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_IsRelatedBy_inverse;
					continue;
				}
				shared_ptr<IfcOrganizationRelationship> self_candidate( *it_IsRelatedBy_inverse );
				if( self_candidate.get() == this )
				{
					it_IsRelatedBy_inverse= IsRelatedBy_inverse.erase( it_IsRelatedBy_inverse );
				}
				else
				{
					++it_IsRelatedBy_inverse;
				}
			}
		}
	}
	if( m_RelatingOrganization )
	{
		std::vector<weak_ptr<IfcOrganizationRelationship> >& Relates_inverse = m_RelatingOrganization->m_Relates_inverse;
		for( auto it_Relates_inverse = Relates_inverse.begin(); it_Relates_inverse != Relates_inverse.end(); )
		{
			weak_ptr<IfcOrganizationRelationship> self_candidate_weak = *it_Relates_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_Relates_inverse;
				continue;
			}
			shared_ptr<IfcOrganizationRelationship> self_candidate( *it_Relates_inverse );
			if( self_candidate.get() == this )
			{
				it_Relates_inverse= Relates_inverse.erase( it_Relates_inverse );
			}
			else
			{
				++it_Relates_inverse;
			}
		}
	}
}
