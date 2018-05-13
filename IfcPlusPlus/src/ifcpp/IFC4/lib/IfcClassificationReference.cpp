/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcClassification.h"
#include "ifcpp/IFC4/include/IfcClassificationReference.h"
#include "ifcpp/IFC4/include/IfcClassificationReferenceSelect.h"
#include "ifcpp/IFC4/include/IfcExternalReferenceRelationship.h"
#include "ifcpp/IFC4/include/IfcIdentifier.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcRelAssociatesClassification.h"
#include "ifcpp/IFC4/include/IfcText.h"
#include "ifcpp/IFC4/include/IfcURIReference.h"

// ENTITY IfcClassificationReference 
IfcClassificationReference::IfcClassificationReference() {}
IfcClassificationReference::IfcClassificationReference( int id ) { m_entity_id = id; }
IfcClassificationReference::~IfcClassificationReference() {}
shared_ptr<BuildingObject> IfcClassificationReference::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcClassificationReference> copy_self( new IfcClassificationReference() );
	if( m_Location ) { copy_self->m_Location = dynamic_pointer_cast<IfcURIReference>( m_Location->getDeepCopy(options) ); }
	if( m_Identification ) { copy_self->m_Identification = dynamic_pointer_cast<IfcIdentifier>( m_Identification->getDeepCopy(options) ); }
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_ReferencedSource ) { copy_self->m_ReferencedSource = dynamic_pointer_cast<IfcClassificationReferenceSelect>( m_ReferencedSource->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_Sort ) { copy_self->m_Sort = dynamic_pointer_cast<IfcIdentifier>( m_Sort->getDeepCopy(options) ); }
	return copy_self;
}
void IfcClassificationReference::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCCLASSIFICATIONREFERENCE" << "(";
	if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_ReferencedSource ) { m_ReferencedSource->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Sort ) { m_Sort->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcClassificationReference::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcClassificationReference::toString() const { return L"IfcClassificationReference"; }
void IfcClassificationReference::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 6 ){ std::stringstream err; err << "Wrong parameter count for entity IfcClassificationReference, expecting 6, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_Location = IfcURIReference::createObjectFromSTEP( args[0], map );
	m_Identification = IfcIdentifier::createObjectFromSTEP( args[1], map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_ReferencedSource = IfcClassificationReferenceSelect::createObjectFromSTEP( args[3], map );
	m_Description = IfcText::createObjectFromSTEP( args[4], map );
	m_Sort = IfcIdentifier::createObjectFromSTEP( args[5], map );
}
void IfcClassificationReference::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcExternalReference::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "ReferencedSource", m_ReferencedSource ) );
	vec_attributes.push_back( std::make_pair( "Description", m_Description ) );
	vec_attributes.push_back( std::make_pair( "Sort", m_Sort ) );
}
void IfcClassificationReference::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcExternalReference::getAttributesInverse( vec_attributes_inverse );
	if( m_ClassificationRefForObjects_inverse.size() > 0 )
	{
		shared_ptr<AttributeObjectVector> ClassificationRefForObjects_inverse_vec_obj( new AttributeObjectVector() );
		for( size_t i=0; i<m_ClassificationRefForObjects_inverse.size(); ++i )
		{
			if( !m_ClassificationRefForObjects_inverse[i].expired() )
			{
				ClassificationRefForObjects_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcRelAssociatesClassification>( m_ClassificationRefForObjects_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "ClassificationRefForObjects_inverse", ClassificationRefForObjects_inverse_vec_obj ) );
	}
	if( m_HasReferences_inverse.size() > 0 )
	{
		shared_ptr<AttributeObjectVector> HasReferences_inverse_vec_obj( new AttributeObjectVector() );
		for( size_t i=0; i<m_HasReferences_inverse.size(); ++i )
		{
			if( !m_HasReferences_inverse[i].expired() )
			{
				HasReferences_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcClassificationReference>( m_HasReferences_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "HasReferences_inverse", HasReferences_inverse_vec_obj ) );
	}
}
void IfcClassificationReference::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcExternalReference::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcClassificationReference> ptr_self = dynamic_pointer_cast<IfcClassificationReference>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcClassificationReference::setInverseCounterparts: type mismatch" ); }
	shared_ptr<IfcClassification>  ReferencedSource_IfcClassification = dynamic_pointer_cast<IfcClassification>( m_ReferencedSource );
	if( ReferencedSource_IfcClassification )
	{
		ReferencedSource_IfcClassification->m_HasReferences_inverse.push_back( ptr_self );
	}
	shared_ptr<IfcClassificationReference>  ReferencedSource_IfcClassificationReference = dynamic_pointer_cast<IfcClassificationReference>( m_ReferencedSource );
	if( ReferencedSource_IfcClassificationReference )
	{
		ReferencedSource_IfcClassificationReference->m_HasReferences_inverse.push_back( ptr_self );
	}
}
void IfcClassificationReference::unlinkFromInverseCounterparts()
{
	IfcExternalReference::unlinkFromInverseCounterparts();
	shared_ptr<IfcClassification>  ReferencedSource_IfcClassification = dynamic_pointer_cast<IfcClassification>( m_ReferencedSource );
	if( ReferencedSource_IfcClassification )
	{
		std::vector<weak_ptr<IfcClassificationReference> >& HasReferences_inverse = ReferencedSource_IfcClassification->m_HasReferences_inverse;
		for( auto it_HasReferences_inverse = HasReferences_inverse.begin(); it_HasReferences_inverse != HasReferences_inverse.end(); )
		{
			weak_ptr<IfcClassificationReference> self_candidate_weak = *it_HasReferences_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_HasReferences_inverse;
				continue;
			}
			shared_ptr<IfcClassificationReference> self_candidate( *it_HasReferences_inverse );
			if( self_candidate.get() == this )
			{
				it_HasReferences_inverse= HasReferences_inverse.erase( it_HasReferences_inverse );
			}
			else
			{
				++it_HasReferences_inverse;
			}
		}
	}
	shared_ptr<IfcClassificationReference>  ReferencedSource_IfcClassificationReference = dynamic_pointer_cast<IfcClassificationReference>( m_ReferencedSource );
	if( ReferencedSource_IfcClassificationReference )
	{
		std::vector<weak_ptr<IfcClassificationReference> >& HasReferences_inverse = ReferencedSource_IfcClassificationReference->m_HasReferences_inverse;
		for( auto it_HasReferences_inverse = HasReferences_inverse.begin(); it_HasReferences_inverse != HasReferences_inverse.end(); )
		{
			weak_ptr<IfcClassificationReference> self_candidate_weak = *it_HasReferences_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_HasReferences_inverse;
				continue;
			}
			shared_ptr<IfcClassificationReference> self_candidate( *it_HasReferences_inverse );
			if( self_candidate.get() == this )
			{
				it_HasReferences_inverse= HasReferences_inverse.erase( it_HasReferences_inverse );
			}
			else
			{
				++it_HasReferences_inverse;
			}
		}
	}
}
